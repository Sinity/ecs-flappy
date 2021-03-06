#pragma once
#include <ECS/task.h>
#include <array>
#include <SFML/Graphics.hpp>

class Projection;
struct PositionComponent;
struct SizeComponent;
class CollisionDetector : public Task {
public:
	CollisionDetector(Engine& engine, sf::RenderWindow& window) :
			Task(engine),
			window(window) {
	}
	void update() override;

private:
    sf::Vector2f calculateCollision(const std::array<sf::Vector2f, 4>& first, const std::array<sf::Vector2f, 4>& secnd);
    float overlap(Projection first, Projection second);
    std::array<sf::Vector2f, 4> getVertices(const PositionComponent& position, const SizeComponent& size);
    void appendAxes(std::vector<sf::Vector2f>& where, const std::array<sf::Vector2f, 4>& sourceVertices);

	sf::RenderWindow& window;
};

