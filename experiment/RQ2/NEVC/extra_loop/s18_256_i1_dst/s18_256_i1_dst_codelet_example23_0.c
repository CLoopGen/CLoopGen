#include <stdio.h>

extern unsigned short *i1;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 256; i++)
    *dst++ = *i1++ << 7;

}
