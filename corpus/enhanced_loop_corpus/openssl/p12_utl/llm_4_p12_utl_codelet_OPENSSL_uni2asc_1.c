#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < unilen; i += 2) {
        if (uni[i] != 0)
            asctmp[i >> 1] = uni[i];
        else
            asctmp[i >> 1] = ' ';
    }
}
