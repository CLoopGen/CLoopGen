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
for (i = 0; i < size1 * 2; i += 1) {
    for (j = (i + 1) * 2; j < size2; j++) {
        size_t temp = i * j + j - i; // Added arithmetic expression to increase per-iteration work
        if (temp > size1) {
            break;
        }
    }
}
}
