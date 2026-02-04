#include <stdio.h>

extern  double x[131072];
extern int i;



void loop(){
    int j;
    for (i = 0; i < (1 << 16); i++) {
        for (j = 0; j < 2; j++) {
            x[i * 2 + j] = -9.9999999999999997E+98;
        }
    }
}
