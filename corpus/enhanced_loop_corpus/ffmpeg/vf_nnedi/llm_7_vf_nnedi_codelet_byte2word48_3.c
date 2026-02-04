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
    int16_t temp[48]; // Local accumulation to alter write dependency
    int idx = 0;
    for (y = 0; y < 4; y++) {
        int base_src = y * pitch * 2;
        for (x = 0; x < 12; x++) {
            temp[idx] = t[base_src + x]; // Introduce temporary storage (WAW on temp, but no direct WAW on p)
            idx++;
        }
    }
    // Eliminate loop-carried dependence by separating read and write phases
    for (idx = 0; idx < 48; idx++) {
        p[idx] = temp[idx]; // Final write with no overlap in accesses
    }
}
