#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (dest_size1 > 0) {
        i = 0;
        size_t j;
        do {
            for (j = 0; j < dest_size2; j++) {
            }
            i++;
        } while (i < dest_size1);
    }
}
