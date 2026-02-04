#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    ia[i] = (int)sa[i];
    ia[i + 1] = (int)sa[i + 1];
    ib[i] = (int)sb[i];
    ib[i + 1] = (int)sb[i + 1];
}

}
