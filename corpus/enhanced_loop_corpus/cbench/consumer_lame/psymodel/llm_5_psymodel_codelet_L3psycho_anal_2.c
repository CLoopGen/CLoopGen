#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 513; i++) {
        partition_l[i] = -1;
        if (i == 512) break;
    }
}
