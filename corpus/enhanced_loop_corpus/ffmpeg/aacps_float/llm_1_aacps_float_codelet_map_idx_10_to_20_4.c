#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 1; outer >= 0; outer--) {
        int temp_b = b;
        for (; temp_b >= 0; temp_b--) {
            par_mapped[2 * temp_b + 1] = par_mapped[2 * temp_b] = par[temp_b];
        }
    }
}
