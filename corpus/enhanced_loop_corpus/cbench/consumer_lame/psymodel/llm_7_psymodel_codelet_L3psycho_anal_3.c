#include <stdio.h>

#include <inttypes.h>

extern int npart_l_orig;
extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_npart = npart_l_orig;
    for (i = 0; i < 513; i += 2) {
        int val1 = partition_l[i];
        int val2 = (i + 1 < 513) ? partition_l[i + 1] : val1;
        if (val1 > local_npart) {
            local_npart = val1;
        }
        if (val2 > local_npart) {
            local_npart = val2;
        }
    }
    npart_l_orig = local_npart;
}
