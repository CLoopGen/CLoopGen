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
    for (i = (b + 1) / 2; i >= 0; i--) {
        if (2*i <= b) {
            par_mapped[4 * i + 1] = par_mapped[4 * i] = par[2*i];
        }
        if (2*i + 1 <= b) {
            par_mapped[4 * i + 3] = par_mapped[4 * i + 2] = par[2*i + 1];
        }
    }
}
