#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern short *restrict sc;
extern int *restrict out1;
extern int *restrict out2;
extern int *restrict out3;
extern int i;

void loop(){
for (i = 0; i < 2048 - 1; i += 2) {
    out1[i] = (int)sa[i];
    out1[i + 1] = (int)sa[i + 1];
    out2[i] = (int)sb[i];
    out2[i + 1] = (int)sb[i + 1];
    out3[i] = (int)sc[i];
    out3[i + 1] = (int)sc[i + 1];
}

}
