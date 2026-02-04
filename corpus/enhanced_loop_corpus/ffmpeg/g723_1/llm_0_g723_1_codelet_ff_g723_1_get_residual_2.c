#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *residual;
extern int16_t *prev_excitation;
extern int lag;
extern int offset;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 3; depth++) {
        for (i = 2; i < 60 + 5 - 1; i++)
            residual[i] = prev_excitation[offset + (i - 2) % lag];
    }
}
