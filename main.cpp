#include <SFML/Graphics.hpp>

int main()
{
    // создаём окно
    float width = 800.0f;
    float height = 600.0f;
    float circleRadius = 50.0f;
    sf::RenderWindow app(sf::VideoMode(width, height, 32), "Hello World - SFML");

    sf::CircleShape hero(circleRadius, 3);
    hero.setPosition(width / 2.0f - circleRadius, height / 2.0f - circleRadius);
    hero.setOutlineColor(sf::Color(255.0f, 255.0f, 0));
    hero.setOutlineThickness(5.0f);

    sf::ConvexShape convex;
    convex.setPointCount(5);

    convex.setPoint(0, sf::Vector2f(50.0f, 0.0f));
    convex.setPoint(1, sf::Vector2f(75.0f, 100.0f));
    convex.setPoint(2, sf::Vector2f(0.0f, 30.0f));
    convex.setPoint(3, sf::Vector2f(100.0f, 30.0f));
    convex.setPoint(4, sf::Vector2f(25.0f, 100.0f));

    const std::string cheeseFilePath = "C:\\Users\\student\\Desktop\\cheese.jpg";
    sf::Texture cheeseTexture;
    cheeseTexture.loadFromFile(cheeseFilePath);

    sf::Sprite cheeseStar(cheeseTexture);
    cheeseStar.setTextureRect(sf::IntRect(
        sf::Vector2i(43, 119),
        sf::Vector2i(100, 100))
    );

    // основной цикл
    while (app.isOpen())
    {
        // проверяем события (нажатие кнопки, закрытие окна и т.д.)
        sf::Event event;
        while (app.pollEvent(event))
        {
            // если событие "закрытие окна":
            if (event.type == sf::Event::Closed)
                // закрываем окно 
                app.close();

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Key::Left:
                    hero.move(-10.0f, 0.0f);
                    break;
                case sf::Keyboard::Key::Right:
                    hero.move(10.0f, 0.0f);
                    break;
                case sf::Keyboard::Key::Down:
                    hero.move(0.0f, 10.0f);
                    break;
                case sf::Keyboard::Key::Up:
                    hero.move(0.0f, -10.0f);
                    break;
                }
            }
        }

        // очищаем экран и заливаем его синим цветом
        app.clear(sf::Color(0, 0, 255));

        // Отрисовка круга и звездочки
        app.draw(hero);
        app.draw(cheeseStar);
        app.draw(convex);

        // отображаем на экран
        app.display();
    }

    return 0;
}