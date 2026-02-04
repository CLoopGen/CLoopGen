#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int done = 0; p < q && !done; ) {
    q--;
    if (p >= q) {
        done = 1;
    } else {
        n = *p;
        *p = *q;
        *q = n;
        p++;
    }
}
}
