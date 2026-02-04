#include <stdio.h>

extern unsigned short *src;
extern unsigned int *out;
extern int i;

void loop(){
for (i = 0; i < 2048; i++)
    *out++ = *src++ << 7;

}
