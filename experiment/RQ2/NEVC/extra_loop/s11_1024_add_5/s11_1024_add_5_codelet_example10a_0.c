#include <stdio.h>

extern short *restrict add2;
extern short *restrict s2;
extern short *restrict s3;
extern int *restrict add1;
extern int *restrict i2;
extern int *restrict i3;
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    add1[i] = i2[i] + i3[i];
    add2[i] = s2[i] + s3[i];
}

}
