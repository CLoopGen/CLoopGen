#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < unilen - 1; i += 2)
        asctmp[(i >> 1) + 1] = uni[i];
    if (unilen > 0 && unilen % 2 == 0)
        asctmp[0] = uni[0];
}
