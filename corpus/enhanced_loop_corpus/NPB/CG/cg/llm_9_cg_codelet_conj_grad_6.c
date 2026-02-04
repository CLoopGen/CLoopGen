#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;



void loop(){
    int trip_count = (lastcol - firstcol + 1) * 2;
    for (j = 1; j <= trip_count; j++) {
        int idx = (j % (lastcol - firstcol + 1)) + 1;
        rho = rho + r[idx] * r[idx] * 0.5;
    }
}
