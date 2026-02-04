#include <stdio.h>

#include <inttypes.h>

extern float tmp0;
extern float tmp1;
extern float tmp2;
extern float tmp3;
extern float tmp4;
extern float tmp5;
extern float tmp6;
extern float tmp7;
extern float tmp10;
extern float tmp11;
extern float tmp12;
extern float tmp13;
extern float z1;
extern float z2;
extern float z3;
extern float z4;
extern float z5;
extern float z11;
extern float z13;
extern float *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Consecutive memory access with precomputed index array to simulate indirect access pattern
    static const int idx_map[8][8] = {
        {0, 1, 2, 3, 4, 5, 6, 7},   // Row 0
        {8, 9,10,11,12,13,14,15},   // Row 1
        {16,17,18,19,20,21,22,23},  // Row 2
        {24,25,26,27,28,29,30,31},  // Row 3
        {32,33,34,35,36,37,38,39},  // Row 4
        {40,41,42,43,44,45,46,47},  // Row 5
        {48,49,50,51,52,53,54,55},  // Row 6
        {56,57,58,59,60,61,62,63}   // Row 7
    };

    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        const int *idx = idx_map[ctr]; // Indirect indexing via lookup table
        tmp0 = dataptr[idx[0]] + dataptr[idx[7]];
        tmp7 = dataptr[idx[0]] - dataptr[idx[7]];
        tmp1 = dataptr[idx[1]] + dataptr[idx[6]];
        tmp6 = dataptr[idx[1]] - dataptr[idx[6]];
        tmp2 = dataptr[idx[2]] + dataptr[idx[5]];
        tmp5 = dataptr[idx[2]] - dataptr[idx[5]];
        tmp3 = dataptr[idx[3]] + dataptr[idx[4]];
        tmp4 = dataptr[idx[3]] - dataptr[idx[4]];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        dataptr[idx[0]] = tmp10 + tmp11;
        dataptr[idx[4]] = tmp10 - tmp11;
        z1 = (tmp12 + tmp13) * ((float)0.70710678100000002);
        dataptr[idx[2]] = tmp13 + z1;
        dataptr[idx[6]] = tmp13 - z1;
        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;
        z5 = (tmp10 - tmp12) * ((float)0.38268343300000002);
        z2 = ((float)0.54119609999999996) * tmp10 + z5;
        z4 = ((float)1.3065629649999999) * tmp12 + z5;
        z3 = tmp11 * ((float)0.70710678100000002);
        z11 = tmp7 + z3;
        z13 = tmp7 - z3;
        dataptr[idx[5]] = z13 + z2;
        dataptr[idx[3]] = z13 - z2;
        dataptr[idx[1]] = z11 + z4;
        dataptr[idx[7]] = z11 - z4;
    }
}
