#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int planes[4];
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < (sizeof (planes) / sizeof ((planes)[0])); i += stride) {
        if (i + 1 < (sizeof (planes) / sizeof ((planes)[0]))) {
            ret += planes[i] + planes[i + 1];
        } else {
            ret += planes[i];
        }
    }
}
