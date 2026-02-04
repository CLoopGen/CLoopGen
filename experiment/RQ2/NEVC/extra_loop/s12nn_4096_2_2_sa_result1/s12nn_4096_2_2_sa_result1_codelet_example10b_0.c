#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern short *restrict sc;
extern int *restrict result1;
extern int *restrict result2;
extern int *restrict result3;
extern int i;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    result1[i] = (int)sa[i];
    result1[i + 1] = (int)sa[i + 1];
    result2[i] = (int)sb[i];
    result2[i + 1] = (int)sb[i + 1];
    result3[i] = (int)sc[i];
    result3[i + 1] = (int)sc[i + 1];
}

}
