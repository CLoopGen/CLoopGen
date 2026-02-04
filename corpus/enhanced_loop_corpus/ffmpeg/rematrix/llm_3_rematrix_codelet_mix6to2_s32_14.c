#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t **out;
extern  int32_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping (reverse traversal order)
    for (i = 0; i < len; i++) {
        int idx = len - 1 - i;  // Reverse access pattern
        int64_t t = in[2][idx] * (int64_t)coeffp[0 * 6 + 2] + in[3][idx] * (int64_t)coeffp[0 * 6 + 3];
        out[0][idx] = (((t + in[0][idx] * (int64_t)coeffp[0 * 6 + 0] + in[4][idx] * (int64_t)coeffp[0 * 6 + 4]) + 16384) >> 15);
        out[1][idx] = (((t + in[1][idx] * (int64_t)coeffp[1 * 6 + 1] + in[5][idx] * (int64_t)coeffp[1 * 6 + 5]) + 16384) >> 15);
    }
}
