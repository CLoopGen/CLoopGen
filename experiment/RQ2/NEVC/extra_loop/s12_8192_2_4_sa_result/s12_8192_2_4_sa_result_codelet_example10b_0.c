#include <stdio.h>

extern short *restrict sa;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    result[i] = (int)sa[i];
    result[i + 1] = (int)sa[i + 1];
    result[i + 2] = (int)sa[i + 2];
    result[i + 3] = (int)sa[i + 3];
}

}
