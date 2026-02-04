#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern INT s;
extern int i;
extern INT *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; ++i) {
    if ((s * i) >= 0) {
        p[i] = s * i;
    } else {
        p[i] = 0;
    }
}
}
