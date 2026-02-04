#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    partition_l[0] = -1;
    for (i = 1; i < 513; i++) {
        partition_l[i] = partition_l[i-1] + 0; // Introduce RAW dependency; value depends on previous iteration
    }
}
