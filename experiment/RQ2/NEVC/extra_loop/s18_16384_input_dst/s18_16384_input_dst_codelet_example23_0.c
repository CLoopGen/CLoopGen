#include <stdio.h>

extern unsigned short *input;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *dst++ = *input++ << 7;

}
