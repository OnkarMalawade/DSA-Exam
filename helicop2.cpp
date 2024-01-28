#include <iostream>
#include <conio.h> // For _getch()

using namespace std;

class HelicopterGame {
private:
    int height;
    int helicopterPos;
    int obstaclePos;

public:
    HelicopterGame() : height(10), helicopterPos(height / 2), obstaclePos(height / 2) {}

    void drawGame() {
        system("cls");
        for (int i = 0; i < height; ++i) {
            if (i == helicopterPos) {
                cout << "H"; // Helicopter
            } else if (i == obstaclePos) {
                cout << "X"; // Obstacle
            } else {
                cout << " ";
            }
            cout << endl;
        }
    }

    void updateGame(char input) {
        if (input == 'w' && helicopterPos > 0) {
            --helicopterPos; // Move helicopter up
        } else if (input == 's' && helicopterPos < height - 1) {
            ++helicopterPos; // Move helicopter down
        }

        // Move obstacle to the left
        if (obstaclePos > 0) {
            --obstaclePos;
        } else {
            obstaclePos = height - 1; // Reset obstacle position
        }
    }

    bool checkCollision() {
        return (helicopterPos == obstaclePos);
    }
};

int main() {
    HelicopterGame game;

    while (true) {
        game.drawGame();

        // Check for user input
        if (_kbhit()) {
            char input = _getch();
            game.updateGame(input);
        }

        // Check for collision
        if (game.checkCollision()) {
            cout << "Game Over! Collision occurred.\n";
            break;
        }

        // Introduce a delay to make the game playable
        for (int i = 0; i < 1000000; ++i) {}

        // Uncomment the following line for Windows
        system("cls");
    }

    return 0;
}

