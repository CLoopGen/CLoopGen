#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i;
    for (i = b; i >= 0; i--) {
        par_mapped[2 * i + 1] = par_mapped[2 * i] = par[i];
    }
}
