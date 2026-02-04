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
    char temp_i = *i;
    char temp_j = *j;
    *j = temp_i;
    *i = temp_j;
    i++;
    j++;
}
}
