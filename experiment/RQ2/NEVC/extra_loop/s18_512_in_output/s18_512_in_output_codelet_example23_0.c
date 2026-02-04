#include <stdio.h>

extern unsigned short *in;
extern unsigned int *output;
extern int i;

void loop(){
for (i = 0; i < 512; i++)
    *output++ = *in++ << 7;

}
