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
    ptrdiff_t indices[] = {10, 20, 30, 40, 50}; // Example indirect index set
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_indices; ++i) {
        double delta;
        size_t idx = ilow + indices[i]; // Indirect access with offset
        if (idx <= ihigh) {
            k += 1.;
            mean += delta / k;
        }
    }
}
