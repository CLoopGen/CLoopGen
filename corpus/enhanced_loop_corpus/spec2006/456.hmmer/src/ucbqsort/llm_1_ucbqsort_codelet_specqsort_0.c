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
    char *temp_i;
    for (i = base, hi = base + qsz; i < hi; ) {
        temp_i = i;
        for (int step = 0; step < 1 && temp_i < hi; step++, temp_i++) {
            c = *j;
            *j++ = *temp_i;
            *temp_i = c;
        }
        i = temp_i;
    }
}
