#include <stdio.h>

extern short *restrict sa;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    out[i] = (int)sa[i];
}

}
