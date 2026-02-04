#include <stdio.h>

extern short *restrict mul2;
extern short *restrict s2;
extern short *restrict s3;
extern int *restrict mul1;
extern int *restrict i2;
extern int *restrict i3;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    mul1[i] = i2[i] + i3[i];
    mul2[i] = s2[i] + s3[i];
}

}
