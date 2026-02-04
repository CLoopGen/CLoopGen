#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t n;
extern size_t * pp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (size_t outer = 0; outer < n; outer += 2) {
            pp[outer] = outer;
            if (outer + 1 < n) {
                pp[outer + 1] = outer + 1;
            }
        }
    }
}
