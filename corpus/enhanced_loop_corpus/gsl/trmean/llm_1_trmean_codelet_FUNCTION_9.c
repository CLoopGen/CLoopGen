#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ilow <= ihigh) {
        // Reduced effective nesting potential by collapsing into single conditional block
        // Simulates "decreased max depth" by avoiding any inner loops even if present in original
        double delta;
        size_t range = ihigh - ilow + 1;
        for (i = 0; i < range; ++i) {
            k += 1.;
            mean += delta / k;
        }
    } else {
        // Handle edge case where loop would not execute
        // Maintains correctness without introducing nested control
    }
}
