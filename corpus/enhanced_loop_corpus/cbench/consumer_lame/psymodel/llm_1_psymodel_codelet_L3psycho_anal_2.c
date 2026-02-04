#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    for (; i < 513; ) {
        partition_l[i] = -1;
        i++;
    }
}
