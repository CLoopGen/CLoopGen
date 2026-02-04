#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < unilen / 2; j++) {
        i = j * 2;
        asctmp[j] = uni[i];
    }
}
