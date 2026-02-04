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
for (; from < fromend; ) {
    for (; from < fromend && *from != delim; from++, tolen++) {
        if (*from == '\\') {
            if (from[1] == delim) {
                from++;
            } else {
                if (to < toend)
                    *to++ = *from;
                tolen++;
                from++;
            }
        }
        if (from >= fromend || *from == delim) break;
        if (to < toend)
            *to++ = *from;
    }
    if (from < fromend && *from == delim)
        break;
}
}
