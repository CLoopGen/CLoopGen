#include <stdio.h>

#include <inttypes.h>

extern char *PL_Cmd;
extern char **a;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (s = PL_Cmd; *s;) {
    while (*s && ((*s) == ' ' || (*s) == '\t' || (*s) == '\n' || (*s) == '\r' || (*s) == '\f'))
        s++;
    if (*s)
        *(a++) = s;
    while (*s && !((*s) == ' ' || (*s) == '\t' || (*s) == '\n' || (*s) == '\r' || (*s) == '\f'))
        s++;
    if (*s)
        *s++ = '\x00';
}

}
