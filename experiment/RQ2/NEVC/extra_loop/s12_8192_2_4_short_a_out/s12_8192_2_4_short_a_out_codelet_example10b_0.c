#include <stdio.h>

extern short *restrict short_a;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    out[i] = (int)short_a[i];
    out[i + 1] = (int)short_a[i + 1];
    out[i + 2] = (int)short_a[i + 2];
    out[i + 3] = (int)short_a[i + 3];
}

}
