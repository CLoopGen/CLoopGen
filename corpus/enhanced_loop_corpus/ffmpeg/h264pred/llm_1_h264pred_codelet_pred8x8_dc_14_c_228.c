#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective depth by unrolling the original loop manually (depth reduced via elimination)
    {
        int i = 0;
        dc0 += src[-1 + i * stride] + src[i - stride];
        dc1 += src[4 + i - stride];
        dc2 += src[-1 + (i + 4) * stride];
    }
    {
        int i = 1;
        dc0 += src[-1 + i * stride] + src[i - stride];
        dc1 += src[4 + i - stride];
        dc2 += src[-1 + (i + 4) * stride];
    }
    {
        int i = 2;
        dc0 += src[-1 + i * stride] + src[i - stride];
        dc1 += src[4 + i - stride];
        dc2 += src[-1 + (i + 4) * stride];
    }
    {
        int i = 3;
        dc0 += src[-1 + i * stride] + src[i - stride];
        dc1 += src[4 + i - stride];
        dc2 += src[-1 + (i + 4) * stride];
    }
}
