#include <stdio.h>

extern short *restrict sa;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    out[i] = (int)sa[i];
    out[i + 1] = (int)sa[i + 1];
}

}
