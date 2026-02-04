#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *tau;
extern integer i__;
extern doublereal fc;
extern doublereal df;
extern doublereal ddf;
extern doublereal temp;
extern doublereal temp1;
extern doublereal temp2;
extern doublereal temp3;
extern doublereal dscale[3];
extern doublereal zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_fc = 0.0, local_df = 0.0, local_ddf = 0.0;
    for (i__ = 1; i__ <= 3; ++i__) {
        doublereal inv_diff = 1. / (dscale[i__ - 1] - *tau);
        doublereal scaled_z = zscale[i__ - 1] * inv_diff;
        local_fc += scaled_z / dscale[i__ - 1];
        local_df += scaled_z * inv_diff;
        local_ddf += local_df * inv_diff; // Introduces cumulative dependency (WAW + loop-carried)
    }
    fc += local_fc;
    df += local_df;
    ddf += local_ddf;
}
