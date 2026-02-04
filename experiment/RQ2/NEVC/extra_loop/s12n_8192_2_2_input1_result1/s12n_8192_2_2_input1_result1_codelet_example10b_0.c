#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern int *restrict result1;
extern int *restrict result2;
extern int i;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    result1[i] = (int)input1[i];
    result1[i + 1] = (int)input1[i + 1];
    result2[i] = (int)input2[i];
    result2[i + 1] = (int)input2[i + 1];
}

}
