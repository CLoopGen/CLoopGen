#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int pitch;
extern float *p;
extern  uint8_t *t;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc = 0.0f;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 12; x++) {
            int idx = y * 12 + x;
            int src_idx = y * pitch * 2 + x;
            acc += t[src_idx]; 
            p[idx] = acc; 
        }
    }
}
