#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp1;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    temp1 = energy[0];
    for (i = 1; i < 5; i++) {
        if (energy[i] > temp1)
            temp1 = energy[i];
    }
}
