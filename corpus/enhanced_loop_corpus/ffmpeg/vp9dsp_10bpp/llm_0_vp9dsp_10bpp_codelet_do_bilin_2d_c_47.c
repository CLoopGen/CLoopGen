#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < 1; j++) {
            tmp_ptr[i] = (src[i] + ((mx * (src[i + 1] - src[i]) + 8) >> 4));
        }
    }
}
