#include <stdio.h>
#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

int liberties = 50;
int libs[2] = {0, 1};
struct reading_moves moves;
int k;

void init_vars() {
    liberties = 2; // Set to 2 to not exceed bounds of libs[2]
    libs[0] = 100;
    libs[1] = 200;
    moves.num = 0;
    for (int i = 0; i < 50; i++) {
        moves.pos[i] = 0;
        moves.score[i] = 0;
    }
}