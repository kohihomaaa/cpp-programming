<<<<<<< HEAD
//yo broo
=======
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>

std::string getComputerChoice() {
    std::string options[3] = {"Rock", "Paper", "Scissors"};
    return options[rand() % 3];
}

std::string getResult(const std::string& player, const std::string& computer) {
    if (player == computer) return "Draw!";
    if ((player == "Rock" && computer == "Scissors") ||
        (player == "Paper" && computer == "Rock") ||
        (player == "Scissors" && computer == "Paper"))
        return "You Win!";
    return "You Lose!";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(600, 400), "Rock Paper Scissors");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1; // Make sure arial.ttf is in your project folder
    }

    sf::Text title("Choose Rock, Paper, or Scissors", font, 24);
    title.setPosition(60, 20);
    title.setFillColor(sf::Color::Black);

    sf::Text resultText("", font, 24);
    resultText.setPosition(60, 300);
    resultText.setFillColor(sf::Color::Black);

    sf::RectangleShape buttons[3];
    sf::Text labels[3];
    std::string choices[3] = {"Rock", "Paper", "Scissors"};

    for (int i = 0; i < 3; i++) {
        buttons[i].setSize(sf::Vector2f(140, 60));
        buttons[i].setPosition(60 + i * 160, 120);
        buttons[i].setFillColor(sf::Color(220, 220, 220));
        buttons[i].setOutlineThickness(2);
        buttons[i].setOutlineColor(sf::Color::Black);

        labels[i] = sf::Text(choices[i], font, 22);
        labels[i].setFillColor(sf::Color::Black);
        labels[i].setPosition(buttons[i].getPosition().x + 25, buttons[i].getPosition().y + 15);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (int i = 0; i < 3; i++) {
                    if (buttons[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        std::string playerChoice = choices[i];
                        std::string computerChoice = getComputerChoice();
                        std::string result = "You: " + playerChoice + " | CPU: " + computerChoice +
                                             "\nResult: " + getResult(playerChoice, computerChoice);
                        resultText.setString(result);
                    }
                }
            }
        }

        window.clear(sf::Color(230, 230, 255));
        window.draw(title);
        for (int i = 0; i < 3; i++) {
            window.draw(buttons[i]);
            window.draw(labels[i]);
        }
        window.draw(resultText);
        window.display();
    }

    return 0;
}
>>>>>>> 270f11245355b2d06b391a0bf72affa861a0159c
