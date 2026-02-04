#include <stdio.h>

#include <inttypes.h>

extern int npart_l_orig;
extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 513; i++) {
        int val = partition_l[i];
        if (val <= npart_l_orig) {
            // Do nothing, skip assignment
        } else {
            npart_l_orig = val;
        }
    }
}
