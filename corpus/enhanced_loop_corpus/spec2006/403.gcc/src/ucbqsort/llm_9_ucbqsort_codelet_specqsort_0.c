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
    char *start = base;
    int stride = 4;
    for (i = start; i < start + qsz; i += stride) {
        for (int k = 0; k < stride && (i + k) < (start + qsz); ++k) {
            j = start + qsz - 1 - k;
            c = *j;
            *j = *i;
            *i = c;
        }
    }
}
