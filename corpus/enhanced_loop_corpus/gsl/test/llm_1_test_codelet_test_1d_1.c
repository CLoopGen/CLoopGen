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
    if (stride == 0) return;
    for (size_t block = 0; block < N; block++) {
        size_t base = block * stride;
        for (size_t offset = 1; offset < stride; offset++) {
            size_t i = base + offset;
            status |= (data[i] != (12345. + i));
        }
    }
}
