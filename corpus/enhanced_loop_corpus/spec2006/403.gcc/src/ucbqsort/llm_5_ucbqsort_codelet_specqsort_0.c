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
    for (i = base, hi = base + qsz; i < hi; ) {
        if (i != j) {
            c = *j;
            *j++ = *i;
            *i++ = c;
        } else {
            i++;
            j++;
        }
    }
}
