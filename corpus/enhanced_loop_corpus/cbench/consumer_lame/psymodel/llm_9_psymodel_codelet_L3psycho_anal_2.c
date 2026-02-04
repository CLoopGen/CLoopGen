#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1026; i++) {
        int idx = i >> 1;
        partition_l[idx] = (i & 1) ? partition_l[idx] : -1;
    }
}
