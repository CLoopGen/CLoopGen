#include <stdio.h>

extern double sum[5];
extern int m;



void loop(){
    int i, j;
    for (m = 0; m < 3; m++) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                sum[0] += 0.1;
            }
        }
        sum[m + 1] = 0.0;
    }
}
