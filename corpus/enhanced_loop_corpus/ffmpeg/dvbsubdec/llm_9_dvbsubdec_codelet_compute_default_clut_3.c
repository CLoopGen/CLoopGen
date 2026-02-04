#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*counttab2)[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        int idx1 = (i << 1);
        int idx2 = idx1 + 1;
        counttab2[i + 1][idx1] = 0;
        counttab2[i + 2][idx2] = 0;
        counttab2[i + 3][idx1] = 0;
    }
}
