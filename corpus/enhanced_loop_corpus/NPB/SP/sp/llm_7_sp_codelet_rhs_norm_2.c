#include <stdio.h>

extern double rms[5];
extern int m;



void loop(){
    rms[0] = 0.;
    for (m = 1; m < 5; m++) {
        rms[m] = rms[m-1] + 0.; // Introduce RAW and loop-carried dependency (though value is still 0.)
    }
    // Final pass to ensure all are exactly 0. (WAW dependency eliminated by design)
    for (m = 0; m < 5; m++) {
        rms[m] = 0.;
    }
}
