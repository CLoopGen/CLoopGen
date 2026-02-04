#include <stdio.h>

extern unsigned short *input;
extern unsigned int *out;
extern int i;

void loop(){
for (i = 0; i < 256; i++)
    *out++ = *input++ << 7;

}
