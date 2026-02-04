#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char Intersection;

Intersection board[421];
int score[400];
int move;
int pos;
int best_score;

void init_vars() {
    // Initialize board array with size 421
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4); // values 0, 1, 2, 3 to ensure some pass the condition (board[pos] != 3)
    }

    // Initialize score array with size 400
    for (int i = 0; i < 400; i++) {
        score[i] = (i % 200) - 100; // values in range [-100, 99] to allow meaningful comparison
    }

    // Ensure that at least one score exceeds initial best_score
    move = 0;
    best_score = -101; // lower than any value in score

    // No initialization for pos as it is loop control variable
}