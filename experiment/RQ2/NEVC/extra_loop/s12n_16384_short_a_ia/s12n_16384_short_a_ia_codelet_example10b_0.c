#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    ia[i] = (int)short_a[i];
    ib[i] = (int)short_b[i];
}

}
