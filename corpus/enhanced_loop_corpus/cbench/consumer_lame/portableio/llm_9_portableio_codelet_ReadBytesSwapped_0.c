#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (; p < q - 1; p++, q--) {
        n = *p;
        temp = *q;
        *p = temp;
        *q = n;
    }
}
