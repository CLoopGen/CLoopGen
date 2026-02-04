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
for (; i <= size - 2; i += 2) {
    dst[i + 0] = r = ((r) + (src[i + 0]));
    if (2 == 1)
        continue;
    dst[i + 1] = g = ((g) + (src[i + 1]));
    if (2 == 2)
        continue;
    dst[i + 2] = b = ((b) + (src[i + 2]));
    if (2 == 3)
        continue;
    dst[i + 3] = a = ((a) + (src[i + 3]));
}

}
