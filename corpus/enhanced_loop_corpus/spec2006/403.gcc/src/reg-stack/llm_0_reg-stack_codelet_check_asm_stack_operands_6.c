#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 3; j++)
    for (i = 8; i < (8 + 7) + 1; i++)
        if (!reg_used_as_output[i])
            break;
}
