#include <stdio.h>

extern unsigned short *input;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 8192; i++)
    *res++ = *input++ << 7;

}
