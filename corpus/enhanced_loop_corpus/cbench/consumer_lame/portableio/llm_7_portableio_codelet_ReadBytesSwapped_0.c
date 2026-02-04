#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    char *left = p;
    char *right = q - 1;
    for (i = 0; left + i < right - i; i++) {
        n = *(left + i);
        *(left + i) = *(right - i);
        *(right - i) = n;
    }
}
