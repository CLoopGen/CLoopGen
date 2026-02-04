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
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int idx = j + i * 2;
            dc0 += src[-1 + idx * stride] + src[idx - stride];
            dc1 += src[4 + idx - stride];
            dc2 += src[-1 + (idx + 4) * stride];
            dc3 += src[-1 + (idx + 8) * stride];
            dc4 += src[-1 + (idx + 12) * stride];
        }
    }
}
