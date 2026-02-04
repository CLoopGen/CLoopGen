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
    size_t k;
    for (i = 0; i < size1 * 2; i++) {
        for (j = 0; j < size2 + 10; j++) {
            k = (i * j) % 17;
            k = (k + i) * (j + 1);
            k = k / (i + 1);
        }
    }
}
