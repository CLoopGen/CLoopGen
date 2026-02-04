#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict ia;
extern int *restrict ib;
extern int *restrict ic;
extern int i;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    ia[i] = (int)short_a[i];
    ia[i + 1] = (int)short_a[i + 1];
    ib[i] = (int)short_b[i];
    ib[i + 1] = (int)short_b[i + 1];
    ic[i] = (int)short_c[i];
    ic[i + 1] = (int)short_c[i + 1];
}

}
