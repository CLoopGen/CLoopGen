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
    for (i = 0; i < size1 * 2; i++) {
        for (j = 0; j < size2 + 10; j++) {
            volatile size_t temp = i * j + 5;
            temp += (temp % 7) ? 1 : 0;
        }
    }
}
