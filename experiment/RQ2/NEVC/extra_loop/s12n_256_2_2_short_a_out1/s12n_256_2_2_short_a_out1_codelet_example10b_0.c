#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern int *restrict out1;
extern int *restrict out2;
extern int i;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    out1[i] = (int)short_a[i];
    out1[i + 1] = (int)short_a[i + 1];
    out2[i] = (int)short_b[i];
    out2[i + 1] = (int)short_b[i + 1];
}

}
