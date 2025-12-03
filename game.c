#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void startGame() {

    srand(time(0));

    int x = 1;              // player lane (0,1,2)
    int step = 0;           // obstacle vertical position
    int obstaclePos = rand() % 3;
    int score = 0;          // score
    int speed = 150;        // initial speed (higher = slower)

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        // LEFT arrow
                x--;

            if (ch == 77 && x < 2)        // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
        system("cls");

        printf("Score: %d\n", score);
        printf("+-----------+\n");

        // GAME AREA
        for (int i = 0; i < 10; i++) {

            if (i == step) {
                if (obstaclePos == 0)
                    printf("| *         |\n");
                else if (obstaclePos == 1)
                    printf("|     *     |\n");
                else
                    printf("|         * |\n");
            }
            else {
                printf("|           |\n");
            }
        }

        // PLAYER
        if (x == 0)
            printf("| |         |\n");
        else if (x == 1)
            printf("|     |     |\n");
        else
            printf("|         | |\n");

        printf("+-----------+\n");

        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            printf("\nGAME OVER!\n");
            printf("Final Score: %d\n", score);

            printf("\nPress R to Restart or Q to Quit...\n");

            while (1) {
                if (_kbhit()) {
                    char ch = getch();
                    if (ch == 'r' || ch == 'R') {
                        startGame();   // restart game
                        return;
                    }
                    if (ch == 'q' || ch == 'Q') {
                        exit(0);       // quit game
                    }
                }
            }
        }

        Sleep(speed);

        // Move obstacle downward
        step++;

        // Reset after reaching bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
            score++;

            // Increase difficulty
            if (speed > 40)
                speed -= 5;
        }
    }
}

int main() {

    printf("Use LEFT and RIGHT arrow keys to move.\n");
    printf("Press any key to start...\n");
    getch();

    startGame();

    return 0;
}
