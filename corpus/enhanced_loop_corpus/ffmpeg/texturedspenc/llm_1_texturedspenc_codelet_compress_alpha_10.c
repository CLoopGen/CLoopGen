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
    for (y = 0; y < 16; y++) {
        x = y % 4;
        int val = block[3 + x * 4 + (y / 4) * stride];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
    }
}
