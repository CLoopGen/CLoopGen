#include <stdio.h>

extern short *restrict sa;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 8192; i++) {
    result[i] = (int)sa[i];
}

}
