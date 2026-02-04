#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[513];
    for (i = 0; i < 513; i++) {
        temp[i] = -1;
    }
    for (i = 0; i < 513; i++) {
        partition_l[i] = temp[i];
    }
}
