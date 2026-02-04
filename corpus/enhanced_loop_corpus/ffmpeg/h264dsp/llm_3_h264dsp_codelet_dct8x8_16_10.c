#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            static const int scale[] = {13107 * 20, 11428 * 18, 20972 * 32, 12222 * 19, 16777 * 25, 15481 * 24};
            static const int idxmap[] = {0, 3, 4, 3, 3, 1, 5, 1, 4, 5, 2, 5, 3, 1, 5, 1};
            const int idx = idxmap[(y & 3) * 4 + (x & 3)];
            // Modified memory access: indirect access via precomputed index array
            static const int linear_index[64] = {
                0, 1, 2, 3, 4, 5, 6, 7,
                8, 9,10,11,12,13,14,15,
                16,17,18,19,20,21,22,23,
                24,25,26,27,28,29,30,31,
                32,33,34,35,36,37,38,39,
                40,41,42,43,44,45,46,47,
                48,49,50,51,52,53,54,55,
                56,57,58,59,60,61,62,63
            };
            int pos = linear_index[y * 8 + x];
            coef[pos] = ((int64_t)coef[pos] * scale[idx] + (1 << 17)) >> 18;
        }
    }
}
