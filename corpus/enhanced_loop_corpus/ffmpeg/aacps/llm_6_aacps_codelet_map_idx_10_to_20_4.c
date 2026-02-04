#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int8_t temp1, temp2;
    for (; b >= 0; b--) {
        temp1 = par[b];
        temp2 = temp1;
        par_mapped[2 * b] = temp2;
        par_mapped[2 * b + 1] = temp2;
    }
}
