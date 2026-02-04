#include <stdio.h>

extern short *restrict sa;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 64; i += 2) {
    result[i] = (int)sa[i];
}

}
