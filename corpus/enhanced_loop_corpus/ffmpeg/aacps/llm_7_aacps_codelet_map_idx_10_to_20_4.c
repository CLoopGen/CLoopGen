#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = b;
    for (; i >= 0; i--) {
        int8_t val = par[i];
        par_mapped[2 * i] = val;
        if (i < b) {
            par_mapped[2 * i + 1] = par_mapped[2 * i + 2]; // WAW dependency introduced: current write depends on previous iteration's write
        } else {
            par_mapped[2 * i + 1] = val;
        }
    }
}
