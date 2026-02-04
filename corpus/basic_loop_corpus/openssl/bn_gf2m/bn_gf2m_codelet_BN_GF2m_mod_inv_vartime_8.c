#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *cdp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < top; i++)
    cdp[i] = 0;

}
