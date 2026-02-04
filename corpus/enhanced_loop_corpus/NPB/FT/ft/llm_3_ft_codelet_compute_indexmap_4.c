#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
int stride = 4;
int limit = (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4));
for (i = 2 * stride; i <= limit * stride; i += stride) {
    int actual_i = i / stride;
    ex[actual_i] = ex[actual_i - 1] * ex[1];
}
}
