#include <stdio.h>

extern  double x[131072];
extern int i;



void loop(){
    double temp = -9.9999999999999997E+98;
    for (i = 1; i <= 2 * (1 << 16); i++) {
        x[i-1] = temp;
        temp = x[i-1]; // Introduce WAW and RAW dependency: write-after-write and read-after-write
    }
}
