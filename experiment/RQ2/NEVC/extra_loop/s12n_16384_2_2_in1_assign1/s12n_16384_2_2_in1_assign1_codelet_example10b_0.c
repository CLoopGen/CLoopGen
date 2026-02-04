#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern int *restrict assign1;
extern int *restrict assign2;
extern int i;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    assign1[i] = (int)in1[i];
    assign1[i + 1] = (int)in1[i + 1];
    assign2[i] = (int)in2[i];
    assign2[i + 1] = (int)in2[i + 1];
}

}
