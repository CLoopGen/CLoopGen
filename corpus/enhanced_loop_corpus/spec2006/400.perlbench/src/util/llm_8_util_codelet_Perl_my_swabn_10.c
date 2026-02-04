#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    n = (n >> 1) - 1;
    for (i = 0; i <= n; i++) {
        tc = *(s + i);
        *(s + i) = *(e - i);
        *(e - i) = tc;
    }
}
