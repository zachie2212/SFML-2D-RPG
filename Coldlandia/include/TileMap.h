#pragma once
#include <filesystem>
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(std::string tileset, sf::Vector2u tileSize, std::string tiles);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::VertexArray _vertices;
    sf::Texture _tileset;
    std::vector<std::vector<int>> _tiles;

    // Load array of space separated ints from .txt file.
    bool loadTilesFromFile(std::string tile_path);
    int* flattenTiles() const;
    bool load(std::string tileset, sf::Vector2u tileSize, const int* tiles, size_t width, size_t height);
};