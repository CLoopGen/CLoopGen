#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *d;
extern int e;
extern int l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = l - 1; i >= 0; i -= 2, --e) {
        if (d[i] != 0) {
            break;
        }
        if (i > 0 && d[i-1] != 0) {
            --i;
            break;
        }
    }
}
