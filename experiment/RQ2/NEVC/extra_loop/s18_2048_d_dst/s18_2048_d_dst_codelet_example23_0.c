#include <stdio.h>

extern unsigned short *d;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 2048; i++)
    *dst++ = *d++ << 7;

}
