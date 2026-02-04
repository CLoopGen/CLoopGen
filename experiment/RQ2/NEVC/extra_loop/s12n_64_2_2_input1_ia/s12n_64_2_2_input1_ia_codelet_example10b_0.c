#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    ia[i] = (int)input1[i];
    ia[i + 1] = (int)input1[i + 1];
    ib[i] = (int)input2[i];
    ib[i + 1] = (int)input2[i + 1];
}

}
