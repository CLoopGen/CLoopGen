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
    for (i = 0; i < maxband; i++) {
        int r0 = bands[i].res[0];
        int r1 = bands[i].res[1];
        int s0 = bands[i].scfi[0];
        int s1 = bands[i].scfi[1];
        int q0 = bands[i].Q[0];
        int q1 = bands[i].Q[1];
        if ((r0 || r1) && (s0 + s1 + q0 + q1) > 0) {
            cnt++;
        }
    }
}
