#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern double r[];
extern double rho;
extern int j;

void loop(){
for (j = 1; j <= lastcol - firstcol + 1; j++) {
    rho = rho + r[j] * r[j];
}

}
