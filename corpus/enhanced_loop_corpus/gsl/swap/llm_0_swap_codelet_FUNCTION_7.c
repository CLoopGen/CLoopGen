#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < dest_size1; i++) {
        for (j = 0; j < dest_size2; j++) {
            size_t e1;
            size_t e2;
            size_t k;
            for (k = 0; k < dest_size1 && k < dest_size2; k++) {
                e1 = i + j + k;
                e2 = i * j * k;
            }
        }
    }
}
