#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t lut[58671]; // 242*243/2 ≈ 58671 elements to hold all pairs (i,j) with i < j and j < 243
int i;
int j;
int tmp_i;
int tmp_j;
int count;
uint8_t dist;

void init_vars() {
    // No additional initialization needed for scalar variables since they are modified in the loop
    // Array lut is already defined with sufficient size
}