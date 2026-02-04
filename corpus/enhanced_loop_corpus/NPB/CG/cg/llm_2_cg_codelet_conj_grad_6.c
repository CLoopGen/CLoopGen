#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    for (j = 1; j <= lastcol - firstcol + 1; j += 2) {
        rho = rho + r[j] * r[j];
        if (j + 1 <= lastcol - firstcol + 1) {
            rho = rho + r[j + 1] * r[j + 1];
        }
    }
}
