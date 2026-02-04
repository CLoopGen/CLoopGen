#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < len; i++)
    x[i] = data[i];

}
