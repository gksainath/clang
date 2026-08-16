#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

int gameOver;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int nTail;
char dir;

// Setup initial game state
void setup() {
    gameOver = 0;
    dir = 'd';
    x = WIDTH / 2;
    y = HEIGHT / 2;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    score = 0;
}

// Draw the board
void draw() {
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
                printf("O"); // Head
            else if (i == foodY && j == foodX)
                printf("F"); // Food
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

// Handle input
void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = 'a'; break;
            case 'd': dir = 'd'; break;
            case 'w': dir = 'w'; break;
            case 's': dir = 's'; break;
            case 'x': gameOver = 1; break;
        }
    }
}

// Game logic
void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case 'a': x--; break;
        case 'd': x++; break;
        case 'w': y--; break;
        case 's': y++; break;
    }

    // Wall collision
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameOver = 1;

    // Self collision
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    // Food eaten
    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
        nTail++;
    }
}

int main() {
    srand(time(0));
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    printf("\nGame Over!\n");
    printf("Final Score: %d\n", score);

    return 0;
}
