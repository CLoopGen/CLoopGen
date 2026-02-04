#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int is_table[2][16];
int i;

void init_vars() {
    // Initialize is_table with zeros since the loop sets values to 0.0
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 16; col++) {
            is_table[row][col] = 0;
        }
    }
    // Initialize loop index variable
    i = 7;
}