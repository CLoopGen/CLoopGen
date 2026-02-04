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
    size_t temp = 0;
    for (i = 0; i < size1; i++) {
        temp = i * 2;
        for (j = i + 1; j < size2; j++) {
            temp += j;
        }
        // Introduce WAW and RAW dependencies via temp
        temp = temp % 100;
    }
}
