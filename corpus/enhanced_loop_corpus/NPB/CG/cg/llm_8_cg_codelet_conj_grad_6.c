#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    for (j = 1; j <= lastcol - firstcol + 1; j += 2) {
        if (j + 1 <= lastcol - firstcol + 1) {
            rho = rho + r[j] * r[j] + r[j+1] * r[j+1];
        } else {
            rho = rho + r[j] * r[j];
        }
    }
}
