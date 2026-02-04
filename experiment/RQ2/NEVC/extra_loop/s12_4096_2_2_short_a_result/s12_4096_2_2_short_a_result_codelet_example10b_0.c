#include <stdio.h>

extern short *restrict short_a;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    result[i] = (int)short_a[i];
    result[i + 1] = (int)short_a[i + 1];
}

}
