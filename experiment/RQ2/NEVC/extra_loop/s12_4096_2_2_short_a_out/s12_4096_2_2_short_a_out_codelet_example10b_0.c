#include <stdio.h>

extern short *restrict short_a;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    out[i] = (int)short_a[i];
    out[i + 1] = (int)short_a[i + 1];
}

}
