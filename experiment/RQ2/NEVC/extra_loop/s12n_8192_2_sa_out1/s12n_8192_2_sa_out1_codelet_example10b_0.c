#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern int *restrict out1;
extern int *restrict out2;
extern int i;

void loop(){
for (i = 0; i < 8192; i += 2) {
    out1[i] = (int)sa[i];
    out2[i] = (int)sb[i];
}

}
