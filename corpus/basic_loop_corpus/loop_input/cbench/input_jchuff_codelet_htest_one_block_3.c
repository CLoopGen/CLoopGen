#include <stdio.h>
#include <inttypes.h>

typedef short JCOEF;
typedef JCOEF *JCOEFPTR;

const int jpeg_natural_order[64] = {
    0,  1,  8,  16, 9,  2,  3,  10,
    17, 24, 32, 25, 18, 11, 4,  5,
    12, 19, 26, 33, 40, 48, 41, 34,
    27, 20, 13, 6,  7,  14, 21, 28,
    35, 42, 49, 56, 57, 50, 43, 36,
    29, 22, 15, 23, 30, 37, 44, 51,
    58, 59, 52, 45, 38, 31, 39, 46,
    53, 60, 61, 54, 47, 55, 62, 63
};

JCOEF block_data[64];
JCOEFPTR block = block_data;

long ac_counts[256];

int temp;
int nbits;
int k;
int r;

void init_vars() {
    for (int i = 0; i < 64; i++) {
        block_data[i] = (JCOEF)(i * 7 - 128); 
    }
    
    for (int i = 0; i < 256; i++) {
        ac_counts[i] = 0;
    }
    
    temp = 0;
    nbits = 0;
    k = 0;
    r = 0;
}