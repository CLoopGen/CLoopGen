#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int maxsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(maxsf) / sizeof(maxsf[0]); ++i) {
        if (i >= 0) {
            maxsf[i] = 255;
        }
    }
}
