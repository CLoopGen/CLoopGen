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
    for (; from < fromend && tolen < 1024; from++, tolen += 2) {
        if (*from == '\\' && (from + 1) < fromend) {
            if (from[1] == delim) {
                from++;
            } else {
                if (to + 1 < toend) {
                    *to++ = *from;
                    *to++ = *(++from);
                } else {
                    from++;
                }
                tolen++;
            }
        } else if (*from == delim) {
            break;
        } else {
            if (to < toend)
                *to++ = *from;
        }
    }
}
