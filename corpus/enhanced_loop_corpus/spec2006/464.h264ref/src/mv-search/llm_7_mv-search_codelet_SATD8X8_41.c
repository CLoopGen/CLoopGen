#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int i;
extern int sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_sad0 = 0, local_sad1 = 0, local_sad2 = 0, local_sad3 = 0;
    for (i = 0; i < 64; i += 4) {
        local_sad0 += byte_abs[diff[i]];
        if (i + 1 < 64) local_sad1 += byte_abs[diff[i + 1]];
        if (i + 2 < 64) local_sad2 += byte_abs[diff[i + 2]];
        if (i + 3 < 64) local_sad3 += byte_abs[diff[i + 3]];
    }
    sad = local_sad0 + local_sad1 + local_sad2 + local_sad3;
}
