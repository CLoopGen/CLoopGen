#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t stride = 4;
    for (i = 0; i < size1; i += 1) {
        for (j = (i + 1) * stride; j < (ptrdiff_t)(size2 * stride); j += stride) {
            // Strided memory access pattern: accessing elements with a fixed step
            volatile ptrdiff_t offset = j / stride;
            (void)offset;
        }
    }
}
