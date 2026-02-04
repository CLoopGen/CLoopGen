#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dc4 = dc3 = dc2 = dc1 = dc0 = 0;
    for (i = 0; i < 4; i++) {
        int idx0 = -1 + i * stride;
        int idx1 = i - stride;
        int idx2 = 4 + i - stride;
        int idx3 = -1 + (i + 4) * stride;
        int idx4 = -1 + (i + 8) * stride;
        int idx5 = -1 + (i + 12) * stride;

        dc0 = dc0 + src[idx0] + src[idx1];
        dc1 = dc0 + src[idx2]; 
        dc2 = dc1 + src[idx3];
        dc3 = dc2 + src[idx4];
        dc4 = dc3 + src[idx5];
    }
}
