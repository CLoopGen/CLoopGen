#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
for (i = 2; i <= (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4)); i += 2) {
    ex[i] = ex[i - 1] * ex[1];
    if (i + 1 <= (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4))) {
        ex[i + 1] = ex[i] * ex[1];
    }
}
}
