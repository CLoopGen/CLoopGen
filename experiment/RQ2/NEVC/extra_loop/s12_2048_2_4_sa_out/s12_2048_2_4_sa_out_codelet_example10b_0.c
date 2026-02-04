#include <stdio.h>

extern short *restrict sa;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 2048 - 3; i += 4) {
    out[i] = (int)sa[i];
    out[i + 1] = (int)sa[i + 1];
    out[i + 2] = (int)sa[i + 2];
    out[i + 3] = (int)sa[i + 3];
}

}
