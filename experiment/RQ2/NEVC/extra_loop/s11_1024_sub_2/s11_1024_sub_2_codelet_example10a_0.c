#include <stdio.h>

extern short *restrict s1;
extern short *restrict s2;
extern short *restrict s3;
extern int *restrict i1;
extern int *restrict i2;
extern int *restrict i3;
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    i1[i] = i2[i] + i3[i];
    s1[i] = s2[i] + s3[i];
}

}
