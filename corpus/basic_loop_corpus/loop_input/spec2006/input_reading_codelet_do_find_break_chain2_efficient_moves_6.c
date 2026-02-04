#include <stdio.h>
#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

struct reading_moves moves_data;
struct reading_moves *moves = &moves_data;
int apos;
int u;

void init_vars() {
    apos = -1; 
    moves->num = 50;
    for (int i = 0; i < 50; i++) {
        moves->pos[i] = i * 2;
        moves->score[i] = 100;
    }
    moves->pos[25] = apos = (apos); 
}