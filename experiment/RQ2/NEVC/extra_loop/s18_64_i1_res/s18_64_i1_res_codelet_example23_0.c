#include <stdio.h>

extern unsigned short *i1;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 64; i++)
    *res++ = *i1++ << 7;

}
