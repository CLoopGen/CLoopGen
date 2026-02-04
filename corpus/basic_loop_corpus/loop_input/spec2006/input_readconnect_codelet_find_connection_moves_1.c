#include <inttypes.h>

int r;
int distances[362];
int num_moves;

void init_vars() {
    num_moves = 362;
    for (int i = 0; i < num_moves; i++) {
        distances[i] = (i == 0) ? 1000 : 2600 + i;
    }
}