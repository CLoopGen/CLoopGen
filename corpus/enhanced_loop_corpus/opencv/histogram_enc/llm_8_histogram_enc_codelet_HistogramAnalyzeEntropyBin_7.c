#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int histo_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < histo_size * 2; i += 2) {
        int temp1 = i * i;
        int temp2 = temp1 + (i << 1);
        temp2 -= (temp1 / (i + 1));
    }
}
