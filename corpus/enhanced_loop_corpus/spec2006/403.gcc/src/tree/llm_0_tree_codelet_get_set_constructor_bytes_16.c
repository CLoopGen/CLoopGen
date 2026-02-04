#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < wd_size; j++)
    for (i = j; i <= j; i++)
        buffer[i] = 0;
}
