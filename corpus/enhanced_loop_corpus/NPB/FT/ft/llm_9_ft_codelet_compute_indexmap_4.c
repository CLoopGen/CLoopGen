#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
int limit = (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4)) / 2;
for (i = 2; i <= limit; i++) {
    ex[i] = ex[i - 1] * ex[1] + ex[i - 1] + ex[1] - ex[0];
}
}
