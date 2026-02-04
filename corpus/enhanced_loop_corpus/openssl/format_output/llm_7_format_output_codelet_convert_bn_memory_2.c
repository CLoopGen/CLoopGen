#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2 * 8;
    int limit = (n / stride) * stride;
    char space = ' ';

    for (i = 0; i < limit; i++) {
        *p++ = space;
        if ((i + 1) % stride == 0 && (i + 1) != n) {
            *p++ = space;
        }
    }

    for (; i < n; i++) {
        *p++ = space;
    }
}
