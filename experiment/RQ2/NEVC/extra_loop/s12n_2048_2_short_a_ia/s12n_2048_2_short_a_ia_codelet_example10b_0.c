#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 2048; i += 2) {
    ia[i] = (int)short_a[i];
    ib[i] = (int)short_b[i];
}

}
