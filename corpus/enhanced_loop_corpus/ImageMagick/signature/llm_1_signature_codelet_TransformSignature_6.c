#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *p;
extern unsigned int shift;
extern unsigned int T;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by unrolling the original loop to eliminate iteration overhead
    // Fully unrolled version of the original loop with no inner loops, reducing control flow depth
    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[0] = ((unsigned int)((T >> shift) & 4294967295U));
    W[1] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[2] = ((unsigned int)((T >> shift) & 4294967295U));
    W[3] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[4] = ((unsigned int)((T >> shift) & 4294967295U));
    W[5] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[6] = ((unsigned int)((T >> shift) & 4294967295U));
    W[7] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[8] = ((unsigned int)((T >> shift) & 4294967295U));
    W[9] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[10] = ((unsigned int)((T >> shift) & 4294967295U));
    W[11] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[12] = ((unsigned int)((T >> shift) & 4294967295U));
    W[13] = ((unsigned int)((T) & 4294967295U));

    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    W[14] = ((unsigned int)((T >> shift) & 4294967295U));
    W[15] = ((unsigned int)((T) & 4294967295U));
}
