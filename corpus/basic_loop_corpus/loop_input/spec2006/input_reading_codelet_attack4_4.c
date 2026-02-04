#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};

int k;
struct reading_moves moves;

void init_vars() {
    k = 0;
    moves.num = 50;
    for (int i = 0; i < 50; i++) {
        moves.pos[i] = i;
        moves.score[i] = i * 10;
    }
}