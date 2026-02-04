#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern int *restrict result1;
extern int *restrict result2;
extern int i;

void loop(){
for (i = 0; i < 512; i += 2) {
    result1[i] = (int)sa[i];
    result2[i] = (int)sb[i];
}

}
