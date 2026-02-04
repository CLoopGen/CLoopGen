#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int cpp;
extern int i;
extern int64_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++)
        for (i = 0; i < cpp; i++)
            size *= (254 - ' ' + 1);
}
