#include <stdio.h>

#include <inttypes.h>

extern int npart_l_orig;
extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (i = 512; i >= 0; i--) {
        if (partition_l[i] > npart_l_orig)
            npart_l_orig = partition_l[i];
    }
}
