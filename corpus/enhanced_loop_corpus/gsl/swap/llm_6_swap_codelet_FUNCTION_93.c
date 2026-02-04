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
        size_t temp = 0;
        for (j = 0; j < dest_size2; j++) {
            temp += i + j;
        }
        // Introduce a WAW dependency by writing to i based on temp
        i = (temp > 100) ? i : i + 1;
    }
}
