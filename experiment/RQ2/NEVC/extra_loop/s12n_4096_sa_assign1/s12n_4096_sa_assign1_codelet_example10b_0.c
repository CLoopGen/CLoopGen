#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern int *restrict assign1;
extern int *restrict assign2;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    assign1[i] = (int)sa[i];
    assign2[i] = (int)sb[i];
}

}
