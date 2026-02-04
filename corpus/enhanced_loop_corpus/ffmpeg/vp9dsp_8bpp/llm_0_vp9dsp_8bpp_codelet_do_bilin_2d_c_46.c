#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (x = 0; x < w; x++)
            tmp_ptr[x] = (src[x] + ((mx * (src[x + 1] - src[x]) + 8) >> 4));
    }
}
