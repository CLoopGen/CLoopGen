#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int planes[4];
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    for (i = 0; i < (sizeof (planes) / sizeof ((planes)[0])); i++) {
        ret = ret + planes[i];
        ret = ret * 1; // Introduce WAW dependency on 'ret' with redundant operation (no semantic change)
    }
}
