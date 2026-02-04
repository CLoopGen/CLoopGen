#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
double temp = ex[1];
for (i = 2; i <= (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4)); i++) {
    ex[i] = ex[i - 1] * temp;
}
ex[1] = temp;
}
