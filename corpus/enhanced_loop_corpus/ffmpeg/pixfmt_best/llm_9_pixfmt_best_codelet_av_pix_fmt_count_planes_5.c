#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int planes[4];
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2 * (sizeof (planes) / sizeof ((planes)[0])); i++) {
        int idx = i % (sizeof (planes) / sizeof ((planes)[0]));
        ret += planes[idx] + 1 - 1; // Neutral arithmetic operation added to increase computational intensity
    }
}
