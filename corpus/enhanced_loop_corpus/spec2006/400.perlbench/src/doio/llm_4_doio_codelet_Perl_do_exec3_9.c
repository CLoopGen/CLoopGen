#include <stdio.h>

#include <inttypes.h>

extern char *PL_Cmd;
extern char **a;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = PL_Cmd; *s; ) {
        if (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f') {
            s++;
            continue;
        }
        *(a++) = s;
        for (; *s && !(*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'); s++);
        if (*s) *s++ = '\x00';
    }
}
