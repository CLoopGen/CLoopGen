#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < 2; i++) {
            int idx = i + k * 2;
            dc0 += src[-1 + idx * stride] + src[idx - stride];
            dc1 += src[4 + idx - stride];
            dc2 += src[-1 + (idx + 4) * stride];
        }
    }
}
