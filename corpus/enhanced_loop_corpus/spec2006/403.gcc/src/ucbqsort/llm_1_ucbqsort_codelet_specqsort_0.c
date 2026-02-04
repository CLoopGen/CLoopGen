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
    char *outer_i;
    for (i = base, hi = base + qsz; i < hi; i = outer_i) {
        outer_i = i + 1;
        for (char *iter = i; iter < outer_i; iter++) {
            c = *j;
            *j++ = *i;
            *i++ = c;
        }
    }
}
