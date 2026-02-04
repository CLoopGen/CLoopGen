#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1 * dest_size2 && dest_size1 > 0 && dest_size2 > 0; i++) {
        size_t j = i % dest_size2;
        if (j == 0 && i > 0) continue;
        size_t e1 = (i * 3 + j * 2) % 17;
        size_t e2 = (e1 * e1 + 5) % 23;
        e1 += e2 * 2;
    }
}
