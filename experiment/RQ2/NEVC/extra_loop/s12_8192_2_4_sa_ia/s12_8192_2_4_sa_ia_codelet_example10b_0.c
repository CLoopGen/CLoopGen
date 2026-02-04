#include <stdio.h>

extern short *restrict sa;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    ia[i] = (int)sa[i];
    ia[i + 1] = (int)sa[i + 1];
    ia[i + 2] = (int)sa[i + 2];
    ia[i + 3] = (int)sa[i + 3];
}

}
