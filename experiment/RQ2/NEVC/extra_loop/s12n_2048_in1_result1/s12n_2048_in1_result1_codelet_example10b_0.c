#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern int *restrict result1;
extern int *restrict result2;
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    result1[i] = (int)in1[i];
    result2[i] = (int)in2[i];
}

}
