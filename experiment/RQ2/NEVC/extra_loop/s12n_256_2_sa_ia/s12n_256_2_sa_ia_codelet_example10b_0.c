#include <stdio.h>

extern short *restrict sa;
extern short *restrict sb;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 256; i += 2) {
    ia[i] = (int)sa[i];
    ib[i] = (int)sb[i];
}

}
