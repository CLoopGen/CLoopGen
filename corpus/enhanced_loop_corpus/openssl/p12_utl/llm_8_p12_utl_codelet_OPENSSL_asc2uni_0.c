#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < ulen - 4; j += 4) {
        unitmp[j]     = 0;
        unitmp[j + 1] = asc[j >> 1];
        unitmp[j + 2] = 0;
        unitmp[j + 3] = asc[(j + 2) >> 1];
    }
    // Handle leftover elements if ulen is not multiple of 4
    if (j == ulen - 4) {
        unitmp[j]     = 0;
        unitmp[j + 1] = asc[j >> 1];
    }
}
