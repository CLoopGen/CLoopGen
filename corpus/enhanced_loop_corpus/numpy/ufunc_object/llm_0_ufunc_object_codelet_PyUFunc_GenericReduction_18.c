#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int naxes;
extern int axes[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < naxes; ++j) {
    for (i = 0; i <= j; ++i) {
        axes[i] = i;
    }
}
}
