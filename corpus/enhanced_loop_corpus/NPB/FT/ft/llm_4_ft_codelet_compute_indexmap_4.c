#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
for (i = 2; i <= (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4)); i++) {
    if (i % 2 == 0) {
        ex[i] = ex[i - 1] * ex[1];
    } else {
        ex[i] = ex[i - 1];
    }
}
}
