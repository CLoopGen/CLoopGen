#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern int mn;
extern int mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Array (simulate gather access)
    int indices[16];
    int idx = 0;
    for (int iy = 0; iy < 4; iy++) {
        for (int ix = 0; ix < 4; ix++) {
            indices[idx++] = 3 + ix * 4 + iy * stride;
        }
    }
    for (int i = 0; i < 16; i++) {
        int val = block[indices[i]];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
    }
}
