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
    for (i = 0; i < size1 / 2; i += 2) {
        for (j = 0; j < size2; j += 3) {
            volatile size_t product = i * j;
            volatile size_t sum = product + i + j;
            if (sum % 2 == 0) {
                sum += 1;
            }
        }
    }
}
