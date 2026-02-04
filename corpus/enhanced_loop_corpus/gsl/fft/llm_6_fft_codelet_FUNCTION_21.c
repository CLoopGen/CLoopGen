#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t j;
extern size_t k;
extern size_t k1;
extern  size_t q;
extern  size_t p_1;
extern  size_t jump;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k < q; k++) {
    size_t temp_i = i, temp_j = j;
    for (k1 = 0; k1 < p_1; k1++) {
        temp_i++;
        temp_j++;
    }
    i = temp_i;
    j = temp_j;
    j += jump;
}
}
