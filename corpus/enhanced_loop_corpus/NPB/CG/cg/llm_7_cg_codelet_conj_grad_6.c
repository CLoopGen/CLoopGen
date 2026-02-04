#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    double sum1 = 0.0, sum2 = 0.0;
    int N = lastcol - firstcol + 1;
    int remainder = N % 2;
    for (j = 1; j <= N - remainder; j += 2) {
        sum1 = sum1 + r[j] * r[j];
        sum2 = sum2 + r[j+1] * r[j+1];
    }
    if (remainder == 1) {
        sum1 = sum1 + r[N] * r[N];
    }
    rho = rho + sum1 + sum2;
}
