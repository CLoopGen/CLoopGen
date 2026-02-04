#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t k;
extern size_t kk;
extern size_t first;
extern  size_t n;
extern size_t * pp;
extern  size_t * qq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase loop nesting depth by splitting the original loop into two levels
    // Outer loop iterates over chunks, inner loop processes individual elements
    size_t chunk_size = 2;
    for (size_t ci = 1; ci < n; ci += chunk_size) {
        for (i = ci; i < n && i < ci + chunk_size; i++) {
            kk = qq[i];
            if (kk > first) {
                pp[k] = pp[kk];
                k = kk;
            } else {
                pp[k] = first;
                k = kk;
                first = pp[kk];
            }
        }
    }
}
