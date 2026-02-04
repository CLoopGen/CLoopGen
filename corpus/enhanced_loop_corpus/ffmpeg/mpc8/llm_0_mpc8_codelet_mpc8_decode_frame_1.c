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
    int j;
    for (i = 0; i < maxband; i++) {
        for (j = 0; j < 1; j++) {  // Artificially increased loop depth (nested single iteration)
            if (bands[i].res[0] || bands[i].res[1])
                cnt++;
        }
    }
}
