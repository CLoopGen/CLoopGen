#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

struct reading_moves moves_instance;

struct reading_moves *moves = &moves_instance;
int first_move = 0;
int i = 0;
int j = 0;
int maxscore = 0;
int max_at = 0;

void init_vars() {
    moves->num = 50;
    for (int idx = 0; idx < moves->num; idx++) {
        moves->pos[idx] = idx;
        moves->score[idx] = (73819 ^ (idx * 17)) + idx * idx;
    }
}