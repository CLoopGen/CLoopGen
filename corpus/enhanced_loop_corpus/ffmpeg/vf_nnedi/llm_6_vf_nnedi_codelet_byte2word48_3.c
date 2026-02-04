#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t;
extern  int pitch;
extern int16_t *p;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (y = 0; y < 4; y++) {
        int t_offset = y * pitch * 2;
        for (x = 0; x < 12; x++) {
            int p_idx = idx++;
            p[p_idx] = t[t_offset + x];
        }
    }
}
