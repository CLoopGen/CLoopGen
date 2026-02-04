#include <stdio.h>

extern unsigned short *d;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 64; i++)
    *res++ = *d++ << 7;

}
