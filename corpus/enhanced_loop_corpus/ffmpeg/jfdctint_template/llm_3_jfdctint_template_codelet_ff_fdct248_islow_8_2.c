#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp0;
extern int tmp1;
extern int tmp2;
extern int tmp3;
extern int tmp4;
extern int tmp5;
extern int tmp6;
extern int tmp7;
extern int tmp10;
extern int tmp11;
extern int tmp12;
extern int tmp13;
extern int z1;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Access with Dynamic Offset
    // Use a fixed stride pattern but access through an index map to simulate non-unit strides.
    // This variant uses indirect indexing via a constant offset array to achieve strided access,
    // mimicking scenarios where memory layout is non-contiguous or transposed.

    const int offsets[8] = {0, 8, 16, 24, 32, 40, 48, 56};  // Simulate larger stride

    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        tmp0 = dataptr[offsets[0]] + dataptr[offsets[1]];
        tmp1 = dataptr[offsets[2]] + dataptr[offsets[3]];
        tmp2 = dataptr[offsets[4]] + dataptr[offsets[5]];
        tmp3 = dataptr[offsets[6]] + dataptr[offsets[7]];
        tmp4 = dataptr[offsets[0]] - dataptr[offsets[1]];
        tmp5 = dataptr[offsets[2]] - dataptr[offsets[3]];
        tmp6 = dataptr[offsets[4]] - dataptr[offsets[5]];
        tmp7 = dataptr[offsets[6]] - dataptr[offsets[7]];

        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;

        dataptr[offsets[0]] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        dataptr[offsets[4]] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));

        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        dataptr[offsets[2]] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr[offsets[6]] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;

        dataptr[offsets[1]] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        dataptr[offsets[5]] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));

        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        dataptr[offsets[3]] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr[offsets[7]] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        dataptr++;  // Move to next base position in sequence
    }
}
