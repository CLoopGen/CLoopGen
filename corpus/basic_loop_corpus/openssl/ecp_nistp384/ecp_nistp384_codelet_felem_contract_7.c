#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 5; i++)
    cond[i] = ((cond[i] & 72057594037927935L) - 1) >> 63;

}
