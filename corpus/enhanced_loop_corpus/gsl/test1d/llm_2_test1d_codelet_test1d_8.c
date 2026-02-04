#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (i = 0; i < 397; i += 4) {
        if (h->bin[i] != 0)
            status = 1;
        // Ensure bounds safety for remaining elements in stride
        if (i + 1 < 397 && h->bin[i + 1] != 0)
            status = 1;
        if (i + 2 < 397 && h->bin[i + 2] != 0)
            status = 1;
        if (i + 3 < 397 && h->bin[i + 3] != 0)
            status = 1;
    }
}
