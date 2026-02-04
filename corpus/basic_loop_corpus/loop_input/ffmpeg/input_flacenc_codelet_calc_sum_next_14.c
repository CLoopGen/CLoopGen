#include <stdint.h>
#include <stdlib.h>

#define PARTS 256
#define KMAX 31

uint64_t sums[32][256];
int kmax = KMAX;
int i;
int k;
int parts = PARTS;

void init_vars() {
    for (int k = 0; k <= KMAX; k++) {
        for (int i = 0; i < PARTS; i++) {
            sums[k][i] = rand() % 1000;
        }
    }
}