#include <stdio.h>

extern unsigned short *in;
extern unsigned int *result;
extern int i;

void loop(){
for (i = 0; i < 8192; i++)
    *result++ = *in++ << 7;

}
