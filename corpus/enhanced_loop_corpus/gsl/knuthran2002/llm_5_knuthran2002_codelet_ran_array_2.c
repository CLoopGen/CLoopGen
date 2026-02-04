#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 37; i++, j++) {
        unsigned long diff = (aa[j - 100]) - (aa[j - 37]);
        if (diff != 0) {
            ran_x[i] = diff & ((1L << 30) - 1);
        } else {
            ran_x[i] = 0;
        }
    }
}
