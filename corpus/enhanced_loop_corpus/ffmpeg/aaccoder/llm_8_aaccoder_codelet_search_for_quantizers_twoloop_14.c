#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int maxsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < sizeof (maxsf) / sizeof (maxsf[0]); ++i) {
    maxsf[i] = 255 + i * i - i;
    for (j = 0; j < 3; ++j) {
        maxsf[i] += (maxsf[i] >> j) & 1;
    }
}
}
