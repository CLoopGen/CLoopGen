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
    int temp_cnt = 0;
    for (i = 0; i < maxband; i++) {
        temp_cnt += (bands[i].res[0] != 0);
        temp_cnt += (bands[i].res[1] != 0);
    }
    cnt = temp_cnt;
}
