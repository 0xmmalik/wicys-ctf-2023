#define _FORTIFY_SOURCE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_NAME_LENGTH 64

void rescue() {
    printf("\nCongratulations! You've freed Featherly the Friendly Finch!\n");
    FILE *fptr = fopen("flag.txt", "r");
    if (fptr == NULL) {
        printf("\nFlag not found! Contact an organizer.\n");
    }
    char c = getc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = getc(fptr);
    }
    fclose(fptr);
}

void cage(char *input, time_t seed) {
    srand(seed);
    unsigned int canary = rand();
    char name[MAX_NAME_LENGTH];
    strcpy(name, input);

    srand(seed);
    if (rand() != canary) {
        printf("Canary McDevious caught you trying to smash the cage!!\n");
        exit(0);
    }
}

int main(int argc, char **argv) {
    int seed1;
    printf("Provide a seed for the random number generator: ");
    scanf("%d", &seed1);
    getchar();
    srand(seed1);

    int polite = rand() % 10000;

    char input[MAX_INPUT_LENGTH];
    printf("What's your input? ");
    fgets(input, sizeof(input), stdin);

    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    srand(time(NULL));

    time_t cur_time = time(NULL);

    char welcome[MAX_NAME_LENGTH];
    printf("What's your name? ");
    fgets(welcome, sizeof(welcome), stdin);
    printf("Hello, %s", welcome);

    if (polite == 1) {
        printf("Thank you for being polite! Canary McDevious steps aside to let you see Featherly.\n");
        cage(input, cur_time);
    } else {
        printf("Canary McDevious doesn't appreciate your tone...\n");
    }

    return 0;
}
