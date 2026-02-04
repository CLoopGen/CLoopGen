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
extern Band *bands;
extern int maxband;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int prev_index = -1;
    for (i = maxband - 1; i >= 0; i--) {
        if (bands[i].res[0] || bands[i].res[1]) {
            bands[i].msf = mask & 1;
            mask >>= 1;
            if (prev_index != -1) {
                bands[i].Q[0] = bands[prev_index].Q[1] + 1;
            }
            prev_index = i;
        } else {
            bands[i].msf = 0;
        }
    }
}
