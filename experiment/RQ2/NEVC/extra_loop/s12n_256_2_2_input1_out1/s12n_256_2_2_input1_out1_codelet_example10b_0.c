#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern int *restrict out1;
extern int *restrict out2;
extern int i;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    out1[i] = (int)input1[i];
    out1[i + 1] = (int)input1[i + 1];
    out2[i] = (int)input2[i];
    out2[i + 1] = (int)input2[i + 1];
}

}
