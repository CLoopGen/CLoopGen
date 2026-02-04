#include <stdio.h>
#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

struct reading_moves moves_data;
struct reading_moves *moves = &moves_data;
int libs2[2];
int u;

void init_vars() {
    // Initialize libs2 with non-zero values to allow matching
    libs2[0] = 42;
    libs2[1] = 84;

    // Initialize moves->num to a value within array bounds
    moves->num = 50;

    // Initialize pos and score arrays
    for (int i = 0; i < 50; i++) {
        moves->pos[i] = (i == 25) ? libs2[0] : (libs2[0] + i + 1); // Ensure one match at index 25
        moves->score[i] = i * 2;
    }

    // Initialize loop index
    u = 0;
}