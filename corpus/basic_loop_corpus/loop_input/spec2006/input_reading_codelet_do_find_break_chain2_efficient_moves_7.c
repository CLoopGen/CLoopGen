#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

struct reading_moves *moves;
int libs[2];
int u;

void init_vars() {
    // Allocate and initialize the moves structure
    moves = (struct reading_moves *)malloc(sizeof(struct reading_moves));
    if (!moves) return;

    // Initialize num to a value within array bounds (max 50)
    moves->num = 50;

    // Set libs[1] to a value that will be matched in one of the pos entries
    libs[1] = 42;

    // Initialize pos and score arrays
    for (int i = 0; i < moves->num; i++) {
        moves->pos[i] = (i == 30) ? libs[1] : (i * 7 + 1); // Ensure one match at index 30
        moves->score[i] = 100; // Initial score
    }

    // Initialize other variables
    u = 0;
}