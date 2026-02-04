#include <stdio.h>
#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

int libs[2] = { 42, 17 };
int k = 0;
struct reading_moves moves;

void init_vars() {
    moves.num = 0;
    for (int i = 0; i < 50; i++) {
        moves.pos[i] = 0;
        moves.score[i] = 0;
    }
}