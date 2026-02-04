#include <stdio.h>

#include <inttypes.h>

extern int npart_l_orig;
extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npart_l_orig = partition_l[0];
    for (i = 1; i < 256; i++) {
        int idx1 = i;
        int idx2 = 512 - i;
        int val1 = partition_l[idx1];
        int val2 = partition_l[idx2];
        if (val1 > npart_l_orig)
            npart_l_orig = val1;
        if (val2 > npart_l_orig)
            npart_l_orig = val2;
    }
}
