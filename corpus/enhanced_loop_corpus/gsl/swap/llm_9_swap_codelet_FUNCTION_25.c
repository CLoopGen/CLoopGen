#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1 / 2; i++) {
        size_t j, k;
        for (j = 0; j < dest_size2 / 2; j++) {
            for (k = 0; k < 3; k++) {
                j += (i + k) % 4;
            }
        }
    }
}
