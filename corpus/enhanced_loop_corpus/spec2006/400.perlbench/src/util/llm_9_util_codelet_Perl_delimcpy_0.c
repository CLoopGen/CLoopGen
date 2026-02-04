#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern char *toend;
extern char *from;
extern char *fromend;
extern int delim;
extern I32 tolen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tolen = 0;
    I32 skip_next = 0;
    for (; from + 1 < fromend; from += 2, tolen += (skip_next ? 0 : 1)) {
        skip_next = 0;
        if (*from == '\\' && (from[1] == delim)) {
            skip_next = 1;
        } else if (*from == delim) {
            break;
        } else {
            if (to < toend)
                *to++ = *from;
        }
        if (!skip_next && to < toend && *(from + 1) != delim) {
            *to++ = *(from + 1);
            tolen++;
        } else if (!skip_next) {
            tolen++;
        }
    }
    // Handle last character if not processed
    if (!skip_next && from < fromend && *from != delim && to < toend) {
        *to++ = *from;
        tolen++;
    }
}
