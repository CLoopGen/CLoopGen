#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

struct reading_moves *moves;
int saved_num_moves;
int k;

void init_vars() {
    moves = (struct reading_moves *)malloc(sizeof(struct reading_moves));
    if (!moves) return;

    moves->num = 50;
    saved_num_moves = 25;

    for (int i = 0; i < 50; i++) {
        moves->pos[i] = i;
        moves->score[i] = 0;
    }
}