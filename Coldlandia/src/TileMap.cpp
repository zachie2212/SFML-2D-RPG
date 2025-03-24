#include "TileMap.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool TileMap::load(std::string tileset, sf::Vector2u tileSize, const int* tiles, size_t width, size_t height)
{
    // load the tileset texture
    if (!_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    _vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    _vertices.resize(width * height * 6);

    // populate the vertex array, with two triangles per tile
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            const int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            const int tu = tileNumber % (_tileset.getSize().x / tileSize.x);
            const int tv = tileNumber / (_tileset.getSize().x / tileSize.x);

            // get a pointer to the triangles' vertices of the current tile
            sf::Vertex* triangles = &_vertices[(i + j * width) * 6];

            // define the 6 corners of the two triangles
            triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

            // define the 6 matching texture coordinates
            triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

bool TileMap::load(std::string tileset, sf::Vector2u tileSize, std::string tiles)
{
    if (!loadTilesFromFile(tiles))
    {
        return false;
    }
    int* flat_array = flattenTiles();
    bool res = load(tileset, tileSize, flat_array, _tiles.at(0).size(), _tiles.size());
    delete flat_array;
    return res;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &_tileset;

    // draw the vertex array
    target.draw(_vertices, states);
}

bool TileMap::loadTilesFromFile(std::string tile_path) {
    std::ifstream file(tile_path);
    if (!file) {
        return false; // Error: File couldn't be opened
    }

    _tiles.clear(); // Clear previous data

    std::string line;
    int row_count = 0;

    while (std::getline(file, line)) {  // Read file line by line
        std::istringstream iss(line);
        std::vector<int> row;
        int value;

        while (iss >> value) {  // Read space-separated integers
            row.push_back(value);
        }

        if (!row.empty()) {  // Only add non-empty rows
            _tiles.push_back(row);
            row_count++;
        }
    }

    return true;
}

int* TileMap::flattenTiles() const {
    if (_tiles.empty()) return nullptr; // Return null if no tiles

    // Compute total number of elements
    size_t total_size = 0;
    for (const auto& row : _tiles) {
        total_size += row.size();
    }

    // Allocate memory for a contiguous int array
    int* flat_array = new int[total_size];

    // Copy elements row by row
    size_t index = 0;
    for (const auto& row : _tiles) {
        std::memcpy(flat_array + index, row.data(), row.size() * sizeof(int));
        index += row.size();
    }

    return flat_array; // Caller must delete[] this
}