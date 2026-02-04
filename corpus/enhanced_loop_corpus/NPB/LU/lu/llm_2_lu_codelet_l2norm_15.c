#include <stdio.h>

extern double sum[5];
extern int m;



void loop(){
    int i;
    for (i = 4; i >= 0; i--) {
        sum[i] = 0.;
    }
}
