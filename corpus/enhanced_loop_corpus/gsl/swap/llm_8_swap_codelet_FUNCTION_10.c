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
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j += 2) {
            j += (j % 3) ? 1 : 0;
        }
    }
}
