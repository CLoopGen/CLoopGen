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
    for (i = base, hi = base + qsz; i < hi; i += 2) {
        if (i + 1 < hi) {
            c = *i;
            *i = *(i + 1);
            *(i + 1) = c;
        }
    }
}
