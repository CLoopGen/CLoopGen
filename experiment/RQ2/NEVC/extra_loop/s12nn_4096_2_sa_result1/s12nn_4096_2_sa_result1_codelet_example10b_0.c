#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern short *restrict sc;
extern int *restrict result1;
extern int *restrict result2;
extern int *restrict result3;
extern int i;

void loop(){
for (i = 0; i < 4096; i += 2) {
    result1[i] = (int)sa[i];
    result2[i] = (int)sb[i];
    result3[i] = (int)sc[i];
}

}
