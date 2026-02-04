#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int naxes;
extern int axes[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 0; i < naxes; ++i) {
    temp = i * i + 2 * i + 1;
    axes[i] = temp;
}
}
