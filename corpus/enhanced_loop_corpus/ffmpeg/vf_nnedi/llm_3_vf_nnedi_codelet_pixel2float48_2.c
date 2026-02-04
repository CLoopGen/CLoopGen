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
    // Variant 2: Strided memory access with fixed offset jumps (transpose-like pattern)
    for (x = 0; x < 12; x++) {
        for (y = 0; y < 4; y++) {
            p[y + x * 4] = t[y * pitch * 2 + x];  // Transpose indexing in destination
        }
    }
}
