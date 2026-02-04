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
    if (maxband > 0) {
        i = 0;
        for (;;) {  // Simulated deeper structure using infinite for with manual control (still avoids while/do-while)
            if (i >= maxband) break;
            if (bands[i].res[0] || bands[i].res[1])
                cnt++;
            i++;
        }
    }
}
