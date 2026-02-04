#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp1;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_local = temp1;
    for (i = 0; i < 5; i++) {
        temp_local = (energy[i] > temp_local) ? energy[i] : temp_local;
    }
    temp1 = temp_local;
}
