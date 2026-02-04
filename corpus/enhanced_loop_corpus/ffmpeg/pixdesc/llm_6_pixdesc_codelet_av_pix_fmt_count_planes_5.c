#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int planes[4];
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < (sizeof (planes) / sizeof ((planes)[0])); i++)
        temp += planes[i];
    ret += temp;
}
