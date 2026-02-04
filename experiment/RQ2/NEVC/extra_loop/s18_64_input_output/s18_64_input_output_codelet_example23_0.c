#include <stdio.h>

extern unsigned short *input;
extern unsigned int *output;
extern int i;

void loop(){
for (i = 0; i < 64; i++)
    *output++ = *input++ << 7;

}
