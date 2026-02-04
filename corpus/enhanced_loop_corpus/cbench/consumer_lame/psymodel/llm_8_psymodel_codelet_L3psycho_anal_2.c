#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 513; i += 4) {
        partition_l[i] = -1;
        if (i + 1 < 513) partition_l[i + 1] = -1;
        if (i + 2 < 513) partition_l[i + 2] = -1;
        if (i + 3 < 513) partition_l[i + 3] = -1;
    }
}
