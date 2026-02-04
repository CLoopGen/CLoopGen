#include <stdio.h>

#include <inttypes.h>

extern int npart_l_orig;
extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 513; i += 2) {
        if (partition_l[i] > npart_l_orig)
            npart_l_orig = partition_l[i];
    }
    // Handle odd-sized array by checking last element if stride skips it
    if (512 > 0 && partition_l[512] > npart_l_orig)
        npart_l_orig = partition_l[512];
}
