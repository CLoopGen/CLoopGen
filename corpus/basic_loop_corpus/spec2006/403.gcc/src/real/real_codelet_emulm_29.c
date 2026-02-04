#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i < (6 + 3); i++)
    equot[i] = 0;

}
