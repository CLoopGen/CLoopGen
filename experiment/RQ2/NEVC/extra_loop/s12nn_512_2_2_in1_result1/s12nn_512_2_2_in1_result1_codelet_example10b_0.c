#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern short *restrict in3;
extern int *restrict result1;
extern int *restrict result2;
extern int *restrict result3;
extern int i;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    result1[i] = (int)in1[i];
    result1[i + 1] = (int)in1[i + 1];
    result2[i] = (int)in2[i];
    result2[i + 1] = (int)in2[i + 1];
    result3[i] = (int)in3[i];
    result3[i + 1] = (int)in3[i + 1];
}

}
