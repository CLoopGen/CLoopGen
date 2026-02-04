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
    size_t temp_index = 0;
    double expected = 12345.0;
    for (i = 1; i < N * stride; i++) {
        temp_index = (temp_index + i) % (stride == 1 ? 2 : stride);
        if (i % stride == 0)
            continue;
        expected += (i % 2) ? 1.0 : -1.0;
        status |= (data[i] != expected);
        expected = 12345.0 + i + 1;
    }
}
