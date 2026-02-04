#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int32_t ff_vc1_dqscale[63] = {
    8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
    28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
    68, 69, 70
};

int16_t block[64];

int16_t *ac_val;

int q1;
int q2;
int k;
int sh;

void init_vars() {
    // Allocate and initialize ac_val as an array of 8 int16_t values to match loop bounds (k from 1 to 7)
    ac_val = (int16_t*)malloc(8 * sizeof(int16_t));
    for (int i = 0; i < 8; i++) {
        ac_val[i] = (int16_t)(i * 32);
    }

    // Initialize q1 in valid range [1,63] so that ff_vc1_dqscale[q1-1] is safe
    q1 = 32;

    // Initialize q2 to a reasonable value
    q2 = 17;

    // Initialize sh to control shift: use sh=3 so that indices k<<sh go up to 7<<3 = 56, within block[64]
    sh = 3;

    // Initialize block array to prevent undefined behavior during accumulation
    for (int i = 0; i < 64; i++) {
        block[i] = (int16_t)(i * 16);
    }

    // Initialize loop index k (though it will be set in loop)
    k = 0;
}