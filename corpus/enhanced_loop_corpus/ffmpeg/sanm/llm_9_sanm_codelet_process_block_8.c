#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int size;
extern int k;
extern int t;
extern uint8_t colors[2];
extern int8_t *pglyph;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k_start = 0;
int k_step = 2;
int k_end = size;
for (int kk = k_start; kk < k_end; kk += k_step)
    for (int t = 0; t < size; t += 2)
        for (int dk = 0; dk < k_step && (kk + dk) < size; dk++)
            for (int dt = 0; dt < 2 && (t + dt) < size; dt++)
                dst[(t + dt) + (kk + dk) * stride] = colors[!*pglyph++];
}
