#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern short *restrict input3;
extern int *restrict assign1;
extern int *restrict assign2;
extern int *restrict assign3;
extern int i;

void loop(){
for (i = 0; i < 8192; i += 2) {
    assign1[i] = (int)input1[i];
    assign2[i] = (int)input2[i];
    assign3[i] = (int)input3[i];
}

}
