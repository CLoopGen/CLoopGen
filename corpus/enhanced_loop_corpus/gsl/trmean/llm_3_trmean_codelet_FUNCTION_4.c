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
    size_t *indices = (size_t*)malloc((ihigh - ilow + 1) * sizeof(size_t));
    if (!indices) return;
    for (size_t idx = 0; idx <= ihigh - ilow; ++idx) {
        indices[idx] = ilow + idx;
    }
    for (size_t j = 0; j <= ihigh - ilow; ++j) {
        i = indices[j];
        double delta;
        k += 1.;
        mean += delta / k;
    }
    free(indices);
}
