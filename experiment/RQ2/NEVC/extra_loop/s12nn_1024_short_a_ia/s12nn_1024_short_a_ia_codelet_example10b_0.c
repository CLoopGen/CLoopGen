#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict ia;
extern int *restrict ib;
extern int *restrict ic;
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    ia[i] = (int)short_a[i];
    ib[i] = (int)short_b[i];
    ic[i] = (int)short_c[i];
}

}
