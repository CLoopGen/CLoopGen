#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *tau;
extern integer i__;
extern real fc;
extern real df;
extern real ddf;
extern real temp;
extern real temp1;
extern real temp2;
extern real temp3;
extern real dscale[3];
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_fc = 0.0F;
    real local_df = 0.0F;
    real local_ddf = 0.0F;
    real prev_temp1 = 0.0F;

    for (i__ = 1; i__ <= 3; ++i__) {
        temp = 1.F / (dscale[i__ - 1] - *tau);
        temp1 = zscale[i__ - 1] * temp;
        
        if (i__ > 1) {
            temp1 += prev_temp1 * 0.1F; // Introduce artificial loop-carried dependency (WAW + RAW)
        }

        temp2 = temp1 * temp;
        temp3 = temp2 * temp;
        
        local_fc += temp1 / dscale[i__ - 1];
        local_df += temp2;
        local_ddf += temp3;

        prev_temp1 = temp1;
    }

    fc += local_fc;
    df += local_df;
    ddf += local_ddf;
}
