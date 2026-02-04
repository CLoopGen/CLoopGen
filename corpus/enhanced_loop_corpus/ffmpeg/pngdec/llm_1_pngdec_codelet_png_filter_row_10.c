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
    for (; i <= size - 6; i += 6) {
        for (int offset = 0; offset < 6; offset += 3) {
            int idx = i + offset;
            dst[idx + 0] = r = ((r) + (src[idx + 0]));
            if (3 == 1)
                continue;
            dst[idx + 1] = g = ((g) + (src[idx + 1]));
            if (3 == 2)
                continue;
            dst[idx + 2] = b = ((b) + (src[idx + 2]));
            if (3 == 3)
                continue;
            dst[idx + 3] = a = ((a) + (src[idx + 3]));
        }
    }
}
