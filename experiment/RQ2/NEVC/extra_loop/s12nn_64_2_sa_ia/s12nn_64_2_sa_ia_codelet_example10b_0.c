#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern short *restrict sc;
extern int *restrict ia;
extern int *restrict ib;
extern int *restrict ic;
extern int i;

void loop(){
for (i = 0; i < 64; i += 2) {
    ia[i] = (int)sa[i];
    ib[i] = (int)sb[i];
    ic[i] = (int)sc[i];
}

}
