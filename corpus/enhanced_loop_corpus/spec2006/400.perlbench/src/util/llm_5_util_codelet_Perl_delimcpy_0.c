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
for (tolen = 0; from < fromend; from++, tolen++) {
    if (*from != '\\' && *from != delim) {
        if (to < toend)
            *to++ = *from;
        continue;
    }
    if (*from == '\\') {
        if (from[1] == delim) {
            from++;
            tolen--;
        } else if (to < toend) {
            *to++ = *from;
            tolen++;
            from++;
        }
    } else if (*from == delim) {
        break;
    }
}
}
