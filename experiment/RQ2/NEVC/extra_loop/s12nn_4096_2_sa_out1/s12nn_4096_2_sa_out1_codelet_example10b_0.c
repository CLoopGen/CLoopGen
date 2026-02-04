#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern short *restrict sc;
extern int *restrict out1;
extern int *restrict out2;
extern int *restrict out3;
extern int i;

void loop(){
for (i = 0; i < 4096; i += 2) {
    out1[i] = (int)sa[i];
    out2[i] = (int)sb[i];
    out3[i] = (int)sc[i];
}

}
