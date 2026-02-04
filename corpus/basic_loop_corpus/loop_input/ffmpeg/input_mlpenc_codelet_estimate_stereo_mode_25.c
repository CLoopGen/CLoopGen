#include <stdint.h>

enum MLPChMode {
    MLP_CHMODE_LEFT_RIGHT,
    MLP_CHMODE_LEFT_SIDE,
    MLP_CHMODE_RIGHT_SIDE,
    MLP_CHMODE_MID_SIDE
};

uint64_t score[4];
int i;
enum MLPChMode best;

void init_vars() {
    score[0] = 100;
    score[1] = 200;
    score[2] = 50;
    score[3] = 300;
    i = 0;
    best = MLP_CHMODE_LEFT_RIGHT;
}