#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
int limit = (6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4));
for (i = 2; i <= limit; i++) {
    if (ex[1] == 0.0) {
        ex[i] = 0.0;
        continue;
    }
    ex[i] = ex[i - 1] * ex[1];
}
}
