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
    for (i = maxband - 1; i >= 0; i -= 2) {
        if (i < maxband && (bands[i].res[0] || bands[i].res[1])) {
            bands[i].msf = mask & 1;
            mask >>= 1;
        }
        if (i > 0 && (bands[i-1].res[0] || bands[i-1].res[1])) {
            bands[i-1].msf = mask & 1;
            mask >>= 1;
        }
    }
}
