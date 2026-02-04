#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= size - 4; i += 4) {
        int offset = i;
        for (int j = 0; j < 4; j += 1) {
            int idx = offset + j;
            if (j == 0) {
                dst[idx + 0] = r = (((((r) + (last[idx + 0])) >> 1) + (src[idx + 0])) & 255);
                if (1 == 1)
                    continue;
            }
            if (j == 1) {
                dst[idx + 1] = g = (((((g) + (last[idx + 1])) >> 1) + (src[idx + 1])) & 255);
                if (1 == 2)
                    continue;
            }
            if (j == 2) {
                dst[idx + 2] = b = (((((b) + (last[idx + 2])) >> 1) + (src[idx + 2])) & 255);
                if (1 == 3)
                    continue;
            }
            if (j == 3) {
                dst[idx + 3] = a = (((((a) + (last[idx + 3])) >> 1) + (src[idx + 3])) & 255);
            }
        }
    }
    // Handle remaining elements if size is not multiple of 4
    for (; i <= size - 1; i += 1) {
        dst[i + 0] = r = (((((r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
        if (1 == 1)
            continue;
        dst[i + 1] = g = (((((g) + (last[i + 1])) >> 1) + (src[i + 1])) & 255);
        if (1 == 2)
            continue;
        dst[i + 2] = b = (((((b) + (last[i + 2])) >> 1) + (src[i + 2])) & 255);
        if (1 == 3)
            continue;
        dst[i + 3] = a = (((((a) + (last[i + 3])) >> 1) + (src[i + 3])) & 255);
    }
}
