#include <stdio.h>

extern short *restrict short_a;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    out[i] = (int)short_a[i];
}

}
