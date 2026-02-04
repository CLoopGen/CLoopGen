#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern  uint8_t *ref;
extern uint8_t *dst;
extern int threshold;
extern int w;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int x = 0; x < w; x++)
    dst[x] = ((src[x] - ref[x]) >= 0 ? (src[x] - ref[x]) : (-(src[x] - ref[x]))) <= threshold ? src[x] : ref[x];

}
