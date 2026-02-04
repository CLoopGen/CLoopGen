#include <stdio.h>

extern unsigned short *in;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 64; i++)
    *res++ = *in++ << 7;

}
