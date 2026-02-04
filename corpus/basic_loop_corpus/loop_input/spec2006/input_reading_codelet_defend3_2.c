#include <stdio.h>
#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

int liberties = 50;
int libs[3] = {0, 1, 2};
struct reading_moves moves;
int k;

void init_vars() {
    liberties = 3; // Set to 3 to not exceed libs array size
    for (int i = 0; i < 3; i++) {
        libs[i] = i * 100;
    }
    moves.num = 0;
}