#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

int16_t block[64];
int tmp0;
int tmp1;
int tmp2;
int tmp3;
int tmp4;
int tmp5;
int tmp6;
int tmp7;
int tmp10;
int tmp11;
int tmp12;
int tmp13;
int z5;
int z10;
int z11;
int z12;
int z13;
int i;
int temp[64];

static int *temp_ptr = temp;
static int16_t *block_ptr = block;

void init_vars() {
    // Initialize scalar variables to zero
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
    tmp3 = 0;
    tmp4 = 0;
    tmp5 = 0;
    tmp6 = 0;
    tmp7 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    z5 = 0;
    z10 = 0;
    z11 = 0;
    z12 = 0;
    z13 = 0;
    i = 0;

    // Seed random number generator for input data
    srand((unsigned int)(time(NULL)));

    // Initialize temp array with random data
    for (int idx = 0; idx < 64; idx++) {
        temp[idx] = rand() % 1024 - 512; // Small integers around zero
    }

    // Initialize block array to zero
    memset(block, 0, sizeof(block));
}