#include <stdio.h>

extern unsigned short *in;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *dst++ = *in++ << 7;

}
