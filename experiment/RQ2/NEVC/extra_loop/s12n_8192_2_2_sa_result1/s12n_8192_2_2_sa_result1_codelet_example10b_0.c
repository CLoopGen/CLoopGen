#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern int *restrict result1;
extern int *restrict result2;
extern int i;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    result1[i] = (int)sa[i];
    result1[i + 1] = (int)sa[i + 1];
    result2[i] = (int)sb[i];
    result2[i + 1] = (int)sb[i + 1];
}

}
