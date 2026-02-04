#include <stdio.h>

extern unsigned short *src;
extern unsigned int *out;
extern int i;

void loop(){
for (i = 0; i < 512; i++)
    *out++ = *src++ << 7;

}
