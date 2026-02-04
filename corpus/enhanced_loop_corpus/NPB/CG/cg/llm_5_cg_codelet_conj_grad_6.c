#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    int limit = lastcol - firstcol + 1;
    for (j = 1; j <= limit; j++) {
        if (j % 2 == 1) {
            rho = rho + r[j] * r[j];
        }
    }
}
