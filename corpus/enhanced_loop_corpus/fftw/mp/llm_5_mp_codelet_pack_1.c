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
    for (i = l - 1; i >= 0 && d[i] == 0; --i, --e) {
        // Loop continues only if d[i] is zero; exits when non-zero found
    }
    // After loop, 'i' will be the first index (from end) where d[i] != 0, or -1 if all are zero
}
