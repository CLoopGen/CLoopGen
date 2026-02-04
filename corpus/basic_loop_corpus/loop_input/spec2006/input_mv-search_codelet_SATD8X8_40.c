#include <stdint.h>

int i;
int j;
int sad;

int m2[8][8];

void init_vars() {
    sad = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            m2[j][i] = (j * 8 + i) - 4; // Initialize with small values, some negative
        }
    }
}