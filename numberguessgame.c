#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number;
    int guess;
    int attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;
    printf("NUMBER GUESSING GAME\n");

    printf("I have chosen a number between 1 and 100.\n");
    printf("Try to guess it!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        }
        else if (guess < number) {
            printf("Too low! Try again.\n");
        }
        else {
            printf("Congratulations!\n");
            printf("You guessed the number in %d attempts.\n", attempts);
        }

    } while (guess != number);

    return 0;
}