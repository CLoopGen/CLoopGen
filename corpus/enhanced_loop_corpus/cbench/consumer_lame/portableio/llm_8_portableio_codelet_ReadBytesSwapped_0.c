#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; p + i < q - i; i++) {
        n = *(p + i);
        *(p + i) = *(q - i);
        *(q - i) = n;
    }
}
