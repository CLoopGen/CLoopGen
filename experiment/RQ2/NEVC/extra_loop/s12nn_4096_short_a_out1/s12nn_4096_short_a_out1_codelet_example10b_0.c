#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict out1;
extern int *restrict out2;
extern int *restrict out3;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    out1[i] = (int)short_a[i];
    out2[i] = (int)short_b[i];
    out3[i] = (int)short_c[i];
}

}
