#include <stdio.h>

#include <inttypes.h>

extern int qsz;
extern char *base;
extern char c;
extern char *i;
extern char *j;
extern char *hi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (i = base, hi = base + qsz; i < hi; i++, j++) {
        temp = *i;
        *i = *(j + 1);
        *(j + 1) = temp;
    }
}
