#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int is_table[2][16];

void init_vars() {
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 16; col++) {
            is_table[row][col] = rand();
        }
    }
    i = 7;
}