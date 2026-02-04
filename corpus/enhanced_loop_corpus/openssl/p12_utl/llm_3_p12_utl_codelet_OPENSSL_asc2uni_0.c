#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — reverse traversal with stride of 2
    for (i = (ulen - 3) & ~1; i >= 0; i -= 2) {
        // Access unitmp and asc with same logic but in reverse order
        unitmp[i] = 0;
        unitmp[i + 1] = asc[i >> 1];
    }
}
