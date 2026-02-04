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
    for (y = 0; y < 4; y++) {
        x = 0;
        int val = block[3 + x * 4 + y * stride];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
        
        x = 1;
        val = block[3 + x * 4 + y * stride];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
        
        x = 2;
        val = block[3 + x * 4 + y * stride];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
        
        x = 3;
        val = block[3 + x * 4 + y * stride];
        if (val < mn)
            mn = val;
        else if (val > mx)
            mx = val;
    }
}
