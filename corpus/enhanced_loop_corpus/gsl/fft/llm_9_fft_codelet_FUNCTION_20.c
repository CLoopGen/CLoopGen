#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t p_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k1 = 0; k1 < p_1; k1 += 2) {
        size_t sum = 0;
        for (size_t j = 0; j < 10 && (k1 + j) < p_1; j++) {
            sum += (k1 + j) * (k1 + j);
        }
        if (sum % 2 == 0) {
            k1++;
        }
    }
}
