#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

int len;
short *inp;
signed char *outp;
int val;
int sign;
int delta;
int diff;
int step;
int valpred;
int vpdiff;
int _usr_index;
int outputbuffer;
int bufferstep;

void init_vars() {
    const size_t input_size = 131072; // ~256KB of input (131072 * 2 bytes)
    short *input_data = (short*)malloc(input_size * sizeof(short));
    signed char *output_data = (signed char*)malloc(input_size * sizeof(signed char));

    if (!input_data || !output_data) {
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        input_data[i] = (short)(i % 65536 - 32768);
    }

    inp = input_data;
    outp = output_data;
    len = input_size;
    valpred = 0;
    _usr_index = 0;
    step = stepsizeTable[_usr_index];
    bufferstep = 0;
    outputbuffer = 0;
}