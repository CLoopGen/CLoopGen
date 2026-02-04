#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

struct reading_moves moves_data;
struct reading_moves *moves = &moves_data;
int libs[2];
int u;

void init_vars() {
    // Initialize libs with plausible values
    libs[0] = 42; // Value to be matched in pos array
    libs[1] = 84;

    // Ensure num is within the bounds of the arrays (max 50)
    moves->num = 50;

    // Initialize pos and score arrays
    for (int i = 0; i < moves->num; i++) {
        moves->pos[i] = (i == 30) ? libs[0] : (libs[0] + i + 1); // Only one match at index 30
        moves->score[i] = 100;
    }

    // Initialize loop index
    u = 0;
}