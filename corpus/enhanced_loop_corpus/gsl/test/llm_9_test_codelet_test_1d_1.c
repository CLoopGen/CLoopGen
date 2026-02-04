#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t stride;
extern size_t i;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = N * stride;
    for (i = 1; i < limit; i++) {
        size_t index = i;
        double expected = 12345.0 + index;
        // Increase arithmetic intensity with redundant but safe operations
        expected = (expected * 1.0) + 0.0;
        status |= (data[index] != expected);
    }
}
