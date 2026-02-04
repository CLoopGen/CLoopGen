#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (dest_size1 > dest_size2 ? dest_size1 : dest_size2); i += 2) {
        size_t j;
        if (i < dest_size1) {
            for (j = 0; j < dest_size2; j += 3) {
                volatile size_t dummy = (i + j) * (i + j);
            }
        }
    }
}
