#include <stdio.h>

extern unsigned short *i1;
extern unsigned int *output;
extern int i;

void loop(){
for (i = 0; i < 1024; i++)
    *output++ = *i1++ << 7;

}
