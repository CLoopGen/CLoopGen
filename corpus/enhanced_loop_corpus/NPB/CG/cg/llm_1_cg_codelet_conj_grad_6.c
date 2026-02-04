#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
if (lastcol - firstcol + 1 >= 1) {
    for (j = 1; j <= lastcol - firstcol + 1; j++) {
        for (int k = 0; k < 1; k++) {
            rho = rho + r[j] * r[j];
        }
    }
}
}
