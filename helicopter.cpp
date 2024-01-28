#include <iostream>
#include <conio.h>
#include <windows.h>  // For sleep function

using namespace std;

class HelicopterGame {
private:
    int helicopterPosition;
    int obstaclePosition;
    int score;

public:
    HelicopterGame() : helicopterPosition(10), obstaclePosition(30), score(0) {}

    void drawGame() {
        system("cls");  // Clear the console screen

        // Draw helicopter
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 50; ++j) {
                if (j == helicopterPosition && i >= 8 && i <= 11) {
                    cout << "^";
                } else if (j == obstaclePosition && i >= 8 && i <= 11) {
                    cout << "#";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }

        // Display score
        cout << "Score: " << score << endl;
    }

    void updateGame() {
        // Move obstacle to the left
        --obstaclePosition;

        // Check for collision
        if (helicopterPosition == obstaclePosition && helicopterPosition >= 0 && helicopterPosition < 50) {
            gameOver();
        }

        // Check if obstacle passed
        if (obstaclePosition < 0) {
            obstaclePosition = 49;
            ++score;
        }
    }

    void getInput() {
        if (_kbhit()) {  // Check if a key is pressed
            char key = _getch();
            if (key == ' ') {
                // Move helicopter up
                --helicopterPosition;
            }
        }
    }

    void gameOver() {
        system("cls");
        cout << "Game Over!\n";
        cout << "Your Score: " << score << endl;
        exit(0);
    }

    void runGame() {
        while (true) {
            drawGame();
            updateGame();
            getInput();
            Sleep(100);  // Slow down the game (100 milliseconds)
        }
    }
};

int main() {
    HelicopterGame game;
    game.runGame();

    return 0;
}
    
