#include <stdio.h>

extern short *restrict sa;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    ia[i] = (int)sa[i];
}

}
