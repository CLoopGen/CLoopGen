#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (q--; p < q; p++) {
        temp = *p;
        *p = *(q - (p - (p + 1)));
        *(q - (p - (p + 1))) = temp;
    }
}
