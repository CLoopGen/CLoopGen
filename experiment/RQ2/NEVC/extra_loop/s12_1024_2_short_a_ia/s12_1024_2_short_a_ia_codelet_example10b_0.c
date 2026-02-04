#include <stdio.h>

extern short *restrict short_a;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 1024; i += 2) {
    ia[i] = (int)short_a[i];
}

}
