#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < (ulen - 2) / 2; ++j) {
        int i = j * 2;
        unitmp[i] = 0;
        unitmp[i + 1] = asc[j];
    }
}
