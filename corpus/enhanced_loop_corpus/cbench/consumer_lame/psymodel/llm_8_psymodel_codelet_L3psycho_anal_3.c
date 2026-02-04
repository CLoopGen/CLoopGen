#include <stdio.h>

#include <inttypes.h>

extern int npart_l_orig;
extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max = npart_l_orig;
    for (i = 0; i < 513; i += 3) {
        if (partition_l[i] > temp_max)
            temp_max = partition_l[i];
        if (i + 1 < 513 && partition_l[i + 1] > temp_max)
            temp_max = partition_l[i + 1];
        if (i + 2 < 513 && partition_l[i + 2] > temp_max)
            temp_max = partition_l[i + 2];
    }
    npart_l_orig = temp_max;
}
