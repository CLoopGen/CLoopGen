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
    int temp_mn = mn;
    int temp_mx = mx;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int idx = 3 + x * 4 + y * stride;
            int val = block[idx];
            temp_mn = (val < temp_mn) ? val : temp_mn;
            temp_mx = (val > temp_mx) ? val : temp_mx;
        }
    }
    mn = temp_mn;
    mx = temp_mx;
}
