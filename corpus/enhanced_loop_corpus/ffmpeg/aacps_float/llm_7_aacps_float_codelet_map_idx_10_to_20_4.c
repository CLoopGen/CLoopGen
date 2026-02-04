#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset;
    for (; b >= 0; b--) {
        offset = 2 * b;
        par_mapped[offset] = par[b];
        par_mapped[offset + 1] = par[b];
    }
}
