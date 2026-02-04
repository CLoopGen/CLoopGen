#include <stdio.h>

#include <inttypes.h>

extern char *str;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < j; i++)
    *str++ = ' ';

}
