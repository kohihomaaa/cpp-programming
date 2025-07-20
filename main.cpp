#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

// Terminal color codes
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define BOLD        "\033[1m"

void enableUTF8() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

std::string getComputerChoice() {
    std::string choices[3] = {"rock", "paper", "scissors"};
    return choices[rand() % 3];
}

std::string getResult(const std::string& player, const std::string& computer) {
    if (player == computer) return "draw";
    if ((player == "rock" && computer == "scissors") ||
        (player == "paper" && computer == "rock") ||
        (player == "scissors" && computer == "paper")) {
        return "win";
    }
    return "lose";
}

void printBanner() {
    std::cout << CYAN << BOLD << R"(
╔════════════════════════════════════════╗
║         ROCK  PAPER  SCISSORS          ║
╚════════════════════════════════════════╝
)" << RESET;
}

void printChoiceArt(const std::string& choice) {
    if (choice == "rock") {
        std::cout << YELLOW << R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)" << RESET;
    } else if (choice == "paper") {
        std::cout << YELLOW << R"(
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
)" << RESET;
    } else if (choice == "scissors") {
        std::cout << YELLOW << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)" << RESET;
    }
}

void printScore(int wins, int losses, int draws) {
    std::cout << CYAN << R"(
═════════════════ 📊 SCOREBOARD 📊 ═════════════════
)" << RESET;
    std::cout << GREEN << "🏆 Wins:    " << wins << RESET << "\n";
    std::cout << RED   << "💀 Losses: " << losses << RESET << "\n";
    std::cout << YELLOW << "⚖️  Draws:   " << draws << RESET << "\n";
    std::cout << CYAN << "═══════════════════════════════════════════\n" << RESET;
}

void printDivider() {
    std::cout << CYAN << "-------------------------------------------\n" << RESET;
}

int main() {
    enableUTF8();
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int wins = 0, losses = 0, draws = 0;
    std::string playerChoice;

    printBanner();

    while (true) {
        std::cout << BOLD << "\n🎮 Enter rock, paper, scissors or 'exit': " << RESET;
        std::cin >> playerChoice;

        std::transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(),
                       [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

        if (playerChoice == "exit") {
            std::cout << GREEN << "\n👋 Thanks for playing! Final score below.\n" << RESET;
            break;
        }

        if (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
            std::cout << RED << "🚫 Invalid choice. Try again.\n" << RESET;
            continue;
        }

        std::string computerChoice = getComputerChoice();
        std::string result = getResult(playerChoice, computerChoice);

        printDivider();
        std::cout << "✨ You chose:\n";
        printChoiceArt(playerChoice);

        std::cout << "🤖 Computer chose:\n";
        printChoiceArt(computerChoice);

        if (result == "win") {
            std::cout << GREEN << "\n🎉 You WIN!\n" << RESET;
            ++wins;
        } else if (result == "lose") {
            std::cout << RED << "\n💔 You LOSE.\n" << RESET;
            ++losses;
        } else {
            std::cout << YELLOW << "\n😐 It's a DRAW.\n" << RESET;
            ++draws;
        }

        printScore(wins, losses, draws);
    }

    printScore(wins, losses, draws);
    return 0;
}