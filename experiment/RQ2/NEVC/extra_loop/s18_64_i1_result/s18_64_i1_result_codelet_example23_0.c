#include <stdio.h>

extern unsigned short *i1;
extern unsigned int *result;
extern int i;

void loop(){
for (i = 0; i < 64; i++)
    *result++ = *i1++ << 7;

}
