#include <stdio.h>

extern short *restrict sa;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    result[i] = (int)sa[i];
    result[i + 1] = (int)sa[i + 1];
}

}
