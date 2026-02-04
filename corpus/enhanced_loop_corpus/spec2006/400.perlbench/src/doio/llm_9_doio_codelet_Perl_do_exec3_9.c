#include <stdio.h>

#include <inttypes.h>

extern char *PL_Cmd;
extern char **a;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    s = PL_Cmd;
    for (; s[i]; ) {
        for (; s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\f'); i++);
        if (s[i]) {
            *(a++) = &s[i];
        }
        for (; s[i] && !(s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\f'); i++);
        if (s[i]) {
            s[i++] = '\x00';
        }
    }
}
