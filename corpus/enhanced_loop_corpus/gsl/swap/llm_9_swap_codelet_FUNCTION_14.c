#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dest_size1; i += 2) {
    size_t j;
    for (j = 0; j < dest_size2; j += 3) {
        size_t e1 = i * j + i * i;
        size_t e2 = j * j + 2 * i + 5;
        e1 += (e1 ^ e2) + j;
        if (e1 >= dest_size2) {
            e2 = (e2 | i) & j;
        }
    }
}
}
