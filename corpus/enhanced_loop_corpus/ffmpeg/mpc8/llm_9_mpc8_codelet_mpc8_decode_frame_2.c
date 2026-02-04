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
    int limit = (maxband + 3) / 4;
    for (i = 0; i < limit; i++) {
        int idx = maxband - 1 - i * 4;
        if (idx >= 0 && (bands[idx].res[0] || bands[idx].res[1])) {
            bands[idx].msf = mask & 1;
            mask >>= 1;
        }
        if (idx - 1 >= 0 && (bands[idx-1].res[0] || bands[idx-1].res[1])) {
            bands[idx-1].msf = mask & 1;
            mask >>= 1;
        }
        if (idx - 2 >= 0 && (bands[idx-2].res[0] || bands[idx-2].res[1])) {
            bands[idx-2].msf = mask & 1;
            mask >>= 1;
        }
        if (idx - 3 >= 0 && (bands[idx-3].res[0] || bands[idx-3].res[1])) {
            bands[idx-3].msf = mask & 1;
            mask >>= 1;
        }
    }
}
