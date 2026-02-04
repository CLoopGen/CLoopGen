#include <stdio.h>

extern  double x[131072];
extern int i;



void loop(){
    int stride = 4;
    for (i = 0; i < 2 * (1 << 16); i++)
        x[i * stride % 131072] = -9.9999999999999997E+98;
}
