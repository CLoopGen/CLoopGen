#include <stdio.h>

extern short *restrict sub2;
extern short *restrict s2;
extern short *restrict s3;
extern int *restrict sub1;
extern int *restrict i2;
extern int *restrict i3;
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    sub1[i] = i2[i] + i3[i];
    sub2[i] = s2[i] + s3[i];
}

}
