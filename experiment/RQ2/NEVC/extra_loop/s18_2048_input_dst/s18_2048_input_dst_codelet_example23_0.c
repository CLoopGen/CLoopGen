#include <stdio.h>

extern unsigned short *input;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 2048; i++)
    *dst++ = *input++ << 7;

}
