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
    int temp = 0;
    for (i = l - 1; i >= 0; --i, --e) {
        temp = d[i] + temp;  // Introduce WAW dependency on temp and RAW on d[i]
        if (d[i] != 0)
            break;
    }
    e += temp;  // Use temp to preserve semantic relevance (avoid dead code)
}
