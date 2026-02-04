#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    // Use strided memory access via index remapping: simulate wider stride in temp output
    int16_t *t = tmp;
    uint8_t *s = src1;
    // Access pattern changed: use indirect indexing with fixed offsets array to modify access pattern
    static const int offsets[8][6] = {
        {-2, -1, 0, 1, 2, 3}, {-1, 0, 1, 2, 3, 4},
        {0, 1, 2, 3, 4, 5}, {1, 2, 3, 4, 5, 6},
        {2, 3, 4, 5, 6, 7}, {3, 4, 5, 6, 7, 8},
        {4, 5, 6, 7, 8, 9}, {5, 6, 7, 8, 9, 10}
    };
    static const int coeffs[6] = {0, -1, 5, 5, -1, 0};
    for (int j = 0; j < 8; j++) {
        t[j] = 0;
        for (int k = 0; k < 6; k++) {
            t[j] += coeffs[k] * s[offsets[j][k]];
        }
    }
    tmp += 8;
    src1 += srcStride;
}
}
