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
    cnt = 0;
    for (i = 1; i <= maxband; i++) {
        int idx = i - 1;
        int r0 = bands[idx].res[0];
        int r1 = bands[idx].res[1];
        if (r0) cnt++;
        if (r1) cnt++;
    }
}
