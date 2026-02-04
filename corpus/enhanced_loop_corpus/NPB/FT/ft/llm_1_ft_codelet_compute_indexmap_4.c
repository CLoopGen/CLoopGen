#include <stdio.h>

extern  double ex[221185];
extern int i;



void loop(){
    int j;
    for (j = 1; j <= 3; j++) {
        for (i = 2 + (j-1)*((6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4)) / 3);
             i <= (j)*(6 * (256 * 256 / 4 + 256 * 256 / 4 + 128 * 128 / 4)) / 3;
             i++) {
            ex[i] = ex[i - 1] * ex[1];
        }
    }
}
