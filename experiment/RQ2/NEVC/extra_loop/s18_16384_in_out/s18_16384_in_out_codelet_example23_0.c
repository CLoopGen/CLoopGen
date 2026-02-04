#include <stdio.h>

extern unsigned short *in;
extern unsigned int *out;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *out++ = *in++ << 7;

}
