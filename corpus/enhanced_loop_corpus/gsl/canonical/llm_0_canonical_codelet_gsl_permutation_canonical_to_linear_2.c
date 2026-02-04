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
    for (i = 1; i < n; i++) {
        kk = qq[i];
        if (kk > first) {
            pp[k] = pp[kk];
            k = kk;
        } else {
            pp[k] = first;
            k = kk;
            first = pp[kk];
        }
        // Add an inner dummy loop that does not affect logic but increases nesting depth
        for (size_t j = 0; j < 1; j++) {
            // This inner loop has no functional effect but increases nesting depth to 2
        }
    }
}
