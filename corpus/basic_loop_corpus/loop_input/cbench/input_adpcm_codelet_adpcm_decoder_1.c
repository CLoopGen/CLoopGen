#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Arrays referenced in the loop
int indexTable[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8
};

int stepsizeTable[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

// Input and output buffers (dynamically sized)
signed char *inp;
short *outp;

// Loop control and state variables
int len;
int sign;
int delta;
int step;
int valpred;
int vpdiff;
int _usr_index; // mapped to 'index' via #define
int inputbuffer;
int bufferstep;

#define index _usr_index

void init_vars() {
    // Allocate large enough data to make loop run ~0.01 seconds
    // Empirical testing suggests ~1M iterations gives desired timing
    const int data_size = 1 << 20; // 1 million elements

    // Initialize scalar variables
    len = data_size;
    sign = 0;
    delta = 0;
    step = 7;
    valpred = 0;
    vpdiff = 0;
    _usr_index = 0;
    inputbuffer = 0;
    bufferstep = 0;

    // Allocate input and output buffers
    inp = (signed char*)malloc(data_size * sizeof(signed char));
    outp = (short*)malloc(data_size * sizeof(short));

    // Initialize input buffer with valid ADPCM-like values (4-bit deltas packed in bytes)
    for (int i = 0; i < data_size; i++) {
        // Random valid 4-bit values: upper nibble and lower nibble will be used
        inp[i] = (rand() % 16) | ((rand() % 16) << 4);
    }

    // Ensure index stays within [0,88] by clamping table values — already satisfied by indexTable content
}