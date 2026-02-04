#include <stdio.h>

extern unsigned short *src;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *res++ = *src++ << 7;

}
