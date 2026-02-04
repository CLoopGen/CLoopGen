#include <stdio.h>

extern unsigned short *in;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 256; i++)
    *res++ = *in++ << 7;

}
