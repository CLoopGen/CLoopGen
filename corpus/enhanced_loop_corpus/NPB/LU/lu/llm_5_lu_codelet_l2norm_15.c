#include <stdio.h>

extern double sum[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        if (m >= 0) {
            sum[m] = 0.;
        }
    }
}
