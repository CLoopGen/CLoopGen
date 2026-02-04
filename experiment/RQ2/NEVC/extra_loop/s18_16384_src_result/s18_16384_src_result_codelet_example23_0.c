#include <stdio.h>

extern unsigned short *src;
extern unsigned int *result;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *result++ = *src++ << 7;

}
