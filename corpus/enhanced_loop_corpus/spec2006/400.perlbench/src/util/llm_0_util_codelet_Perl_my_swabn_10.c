#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    n /= 2;
    for (i = 0; i < n; i++) {
        tc = *s;
        *s = *e;
        *e = tc;
        s++;
        e--;
    }
}
