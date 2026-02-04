#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern int PL_origargc;
extern char **PL_origargv;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < PL_origargc; i++) {
        if (PL_origargv[i] != s + 1 && (!aligned || PL_origargv[i] <= s || PL_origargv[i] > (char *)((UV)(s + 8) & mask))) {
            break;
        }
        s = PL_origargv[i];
        for (; *s; s++);
    }
}
