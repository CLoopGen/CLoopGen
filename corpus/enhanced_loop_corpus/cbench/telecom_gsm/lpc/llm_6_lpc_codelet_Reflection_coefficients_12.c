#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word *temp_r = r;
    for (i = 8; i--; temp_r++, *temp_r = 0)
        ;
}
