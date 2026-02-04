#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= size - 16; i += 16) {
        for (int j = 0; j < 4; ++j) {
            int idx = i + j * 4;
            dst[idx + 0] = r = ((r) + (src[idx + 0]));
            if (4 == 1)
                continue;
            dst[idx + 1] = g = ((g) + (src[idx + 1]));
            if (4 == 2)
                continue;
            dst[idx + 2] = b = ((b) + (src[idx + 2]));
            if (4 == 3)
                continue;
            dst[idx + 3] = a = ((a) + (src[idx + 3]));
        }
    }
}
