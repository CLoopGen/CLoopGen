#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ex;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing row base pointers and accessing elements in a more cache-friendly manner
    uint8_t *base;
    int temp_fx, y_val, fr_val;
    for (x = 0; x <= ex; x++) {
        temp_fx = x * f;
        y_val = temp_fx >> 16;
        fr_val = temp_fx & 65535;
        base = buf + y_val * stride;
        base[x] += (color * (65536 - fr_val)) >> 16;
        if (fr_val) {
            base[stride + x] += (color * fr_val) >> 16;
        }
    }
}
