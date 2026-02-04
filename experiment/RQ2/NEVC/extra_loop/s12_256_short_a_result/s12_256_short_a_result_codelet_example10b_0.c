#include <stdio.h>

extern short *restrict short_a;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 256; i++) {
    result[i] = (int)short_a[i];
}

}
