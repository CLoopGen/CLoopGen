#include <stdio.h>

extern unsigned short *i1;
extern unsigned int *out;
extern int i;

void loop(){
for (i = 0; i < 4096; i++)
    *out++ = *i1++ << 7;

}
