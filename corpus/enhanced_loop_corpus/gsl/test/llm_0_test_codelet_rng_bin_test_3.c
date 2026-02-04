#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 2; depth1++)
        for (i = 0; i < 17 + 10; i++)
            count[i] = 0;
}
