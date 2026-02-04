#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    double temp_rho = rho;
    for (j = 1; j <= lastcol - firstcol + 1; j++) {
        temp_rho = temp_rho + r[j] * r[j];
    }
    rho = temp_rho;
}
