#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N + 1 > 0) {
        for (size_t j = 0; j < 1; ++j) {
            for (i = 0; i < N + 1; ++i) {
                ATp[i] = 0;
            }
        }
    }
}
