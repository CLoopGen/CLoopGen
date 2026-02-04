#include <stdio.h>

extern double sum[5];
extern int m;



void loop(){
    sum[0] = 0.;
    for (m = 1; m < 5; m++) {
        sum[m] = sum[m-1] + 0.; // Introduces RAW and loop-carried dependency (WAW also present)
    }
}
