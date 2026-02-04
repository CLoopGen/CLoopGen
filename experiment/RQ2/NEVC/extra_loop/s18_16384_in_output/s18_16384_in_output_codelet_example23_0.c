#include <stdio.h>

extern unsigned short *in;
extern unsigned int *output;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *output++ = *in++ << 7;

}
