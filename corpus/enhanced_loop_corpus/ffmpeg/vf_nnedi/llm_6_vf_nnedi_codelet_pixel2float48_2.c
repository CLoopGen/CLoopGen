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
    float *temp = p;
    uint8_t *src = t;
    int local_pitch = pitch;
    for (y = 0; y < 4; y++) {
        int base_idx = y * 12;
        int src_offset = y * local_pitch * 2;
        for (x = 0; x < 12; x++) {
            temp[base_idx + x] = (float)src[src_offset + x];
        }
    }
}
