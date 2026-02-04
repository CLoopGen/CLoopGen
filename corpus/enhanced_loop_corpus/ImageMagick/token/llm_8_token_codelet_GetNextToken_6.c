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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Unroll by 2 iterations to reduce loop overhead and increase arithmetic per iteration
    ssize_t limit = (ssize_t)(extent - 1);
    size_t remaining = (size_t)(q - p);
    size_t unroll_step = 2;
    
    for (; remaining >= unroll_step && (p + 1) < q; p += unroll_step, remaining -= unroll_step) {
        if (i < limit) token[i++] = *p;
        if ((size_t)(p - start) >= (extent - 1)) break;

        if (i < limit) token[i++] = *(p + 1);
        if ((size_t)(p + 1 - start) >= (extent - 1)) {
            p++;
            break;
        }
    }
    // Handle leftover elements
    for (; (p < q) && (*p != ','); p++) {
        if (i < limit)
            token[i++] = (*p);
        if ((size_t)(p - start) >= (extent - 1))
            break;
    }
}
