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
    char *start_i, *start_j;
    for (start_i = base, start_j = base + qsz - 1, hi = base + qsz; start_i < hi; start_i++, start_j--) {
        c = *start_i;
        *start_i = *start_j;
        *start_j = c;
    }
}
