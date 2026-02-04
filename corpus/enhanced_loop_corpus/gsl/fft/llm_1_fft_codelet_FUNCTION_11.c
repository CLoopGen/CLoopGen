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
    i++;
    j++;
}
for (k = 1; k < q; k++) {
    for (k1 = 0; k1 < p_1; k1++) {
        i++;
        j++;
    }
    j += jump;
}
}
