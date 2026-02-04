#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1; i++) {
        size_t j = 0;
        for (; j < dest_size2; j++) {
            size_t e1, e2;
            if (j >= i) {
                e1 = i + j;
                e2 = i * j;
            }
        }
    }
}
