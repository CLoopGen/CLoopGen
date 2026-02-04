#include <stdio.h>

extern unsigned short *src;
extern unsigned int *output;
extern int i;

void loop(){
for (i = 0; i < 512; i++)
    *output++ = *src++ << 7;

}
