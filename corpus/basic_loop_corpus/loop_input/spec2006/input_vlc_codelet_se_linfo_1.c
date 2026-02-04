#include <inttypes.h>

int i;
int nn;

void init_vars() {
    nn = 1 << 28; // Large enough to ensure the loop runs ~16 iterations or until nn becomes 0
}