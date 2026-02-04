#include <stdio.h>
#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

int liberties = 4;
int libs[4] = {10, 20, 30, 40};
struct reading_moves moves;
int k;

void init_vars() {
    liberties = 4;
    for (int i = 0; i < 4; i++) {
        libs[i] = i * 10 + 10;
    }
    moves.num = 0;
}