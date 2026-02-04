#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *dst;
extern uint8_t *src;
extern int init_x;
extern int width;
extern int save_upper_left;
extern int save_upper_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_start = init_x + save_upper_left;
    int outer_end = width - save_upper_right;
    int chunk_size = 4;
    int i, x;

    for (i = outer_start; i < outer_end; i += chunk_size) {
        for (x = i; x < i + chunk_size && x < outer_end; x++) {
            dst[x] = src[x];
        }
    }
}
