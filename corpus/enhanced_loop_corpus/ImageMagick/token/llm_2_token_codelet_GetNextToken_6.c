#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *restrict start;
extern  size_t extent;
extern char *restrict token;
extern char *restrict q;
extern  char *restrict p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (; (p < q) && (*p != ','); p += 2) {
        if (i < (ssize_t)(extent - 1))
            token[i++] = (*p);
        if ((size_t)(p - start) >= (extent - 1))
            break;
        // Ensure p does not overshoot q in next iteration
        if (p + 1 >= q) break;
    }
}
