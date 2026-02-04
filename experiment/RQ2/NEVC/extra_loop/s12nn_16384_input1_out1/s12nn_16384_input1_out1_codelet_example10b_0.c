#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern short *restrict input3;
extern int *restrict out1;
extern int *restrict out2;
extern int *restrict out3;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    out1[i] = (int)input1[i];
    out2[i] = (int)input2[i];
    out3[i] = (int)input3[i];
}

}
