#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++)
    for (x = 0; x < 16; x++) {
        int idx = x + y;
        int t_avg = ((top[idx + 0] + 2*top[idx + 1] + top[idx + 2] + 
                      top[idx + 3] + 2*top[idx + 4] + top[idx + 5] + 4) >> 3);
        int l_avg = ((left[idx + 0] + 2*left[idx + 1] + left[idx + 2] + 
                      left[idx + 3] + 2*left[idx + 4] + left[idx + 5] + 4) >> 3);
        d[y * stride + x] = (t_avg + l_avg) >> 1;
    }
}
