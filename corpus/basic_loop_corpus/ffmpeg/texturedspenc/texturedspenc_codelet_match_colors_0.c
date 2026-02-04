#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int dirr;
extern int dirg;
extern int dirb;
extern int dots[16];
extern int stops[4];
extern int x;
extern int y;
extern int k;
extern uint8_t color[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++)
        dots[k++] = block[0 + x * 4 + y * stride] * dirr + block[1 + x * 4 + y * stride] * dirg + block[2 + x * 4 + y * stride] * dirb;
    stops[y] = color[0 + y * 4] * dirr + color[1 + y * 4] * dirg + color[2 + y * 4] * dirb;
}

}
