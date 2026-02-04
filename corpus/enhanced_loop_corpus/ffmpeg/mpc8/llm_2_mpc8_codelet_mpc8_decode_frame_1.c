#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Band {
    int msf;
    int res[2];
    int scfi[2];
    int scf_idx[2][3];
    int Q[2];
} Band;

extern int i;
extern int cnt;
extern Band *bands;
extern int maxband;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolling the loop by accessing two elements at once
    for (i = 0; i < maxband; i += 2) {
        if (i + 1 < maxband) {
            cnt += (bands[i].res[0] || bands[i].res[1]) + (bands[i+1].res[0] || bands[i+1].res[1]);
        } else {
            cnt += (bands[i].res[0] || bands[i].res[1]);
        }
    }
}
