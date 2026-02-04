#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    ia[i] = (int)short_a[i];
    ia[i + 1] = (int)short_a[i + 1];
    ib[i] = (int)short_b[i];
    ib[i + 1] = (int)short_b[i + 1];
}

}
