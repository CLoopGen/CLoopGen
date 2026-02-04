#include <stdio.h>

extern unsigned short *src;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 4096; i++)
    *dst++ = *src++ << 7;

}
