#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern short *restrict input3;
extern int *restrict result1;
extern int *restrict result2;
extern int *restrict result3;
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    result1[i] = (int)input1[i];
    result2[i] = (int)input2[i];
    result3[i] = (int)input3[i];
}

}
