#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < nc; i++)
    nmem[i] = 0;

}
