#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern short *restrict sc;
extern int *restrict ia;
extern int *restrict ib;
extern int *restrict ic;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    ia[i] = ib[i] + ic[i];
    sa[i] = sb[i] + sc[i];
}

}
