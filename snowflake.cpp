#include <SFML/Graphics.hpp>
#include <cmath>

// Recursive function to draw a snowflake-like pattern
void drawSnowflake(sf::RenderWindow& window, float x, float y, float length, float angle, int depth) {
    if (depth == 0) return;  // Base case

    // Calculate end point of the line segment
    float xEnd = x + length * cos(angle);
    float yEnd = y - length * sin(angle);

    // Create a line segment
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x, y)),
        sf::Vertex(sf::Vector2f(xEnd, yEnd))
    };

    // Draw the line segment
    window.draw(line, 2, sf::Lines);

    // Recursively draw smaller "arms" at the end point at different angles
    float newLength = length * 0.6f;  // Reduce length for each recursion level
    drawSnowflake(window, xEnd, yEnd, newLength, angle + M_PI / 4, depth - 1);
    drawSnowflake(window, xEnd, yEnd, newLength, angle - M_PI / 4, depth - 1);
    drawSnowflake(window, xEnd, yEnd, newLength, angle, depth - 1);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Recursive Snowflake");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Center of the snowflake
        float startX = 400, startY = 400;
        float initialLength = 150;  // Starting length of the snowflake arm
        int depth = 5;  // Number of recursion levels

        // Draw snowflake arms from the center
        drawSnowflake(window, startX, startY, initialLength, 0, depth);
        drawSnowflake(window, startX, startY, initialLength, M_PI / 3, depth);
        drawSnowflake(window, startX, startY, initialLength, 2 * M_PI / 3, depth);
        drawSnowflake(window, startX, startY, initialLength, M_PI, depth);
        drawSnowflake(window, startX, startY, initialLength, 4 * M_PI / 3, depth);
        drawSnowflake(window, startX, startY, initialLength, 5 * M_PI / 3, depth);

        window.display();
    }

    return 0;
}
