#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern int *restrict assign1;
extern int *restrict assign2;
extern int i;

void loop(){
for (i = 0; i < 512; i += 2) {
    assign1[i] = (int)in1[i];
    assign2[i] = (int)in2[i];
}

}
