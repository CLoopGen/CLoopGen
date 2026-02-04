#include <stdio.h>

#include <inttypes.h>

extern char *cmd;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = cmd; *s; s++) {
        if (!(((((*s) >= 'A' && (*s) <= 'Z') || ((*s) >= 'a' && (*s) <= 'z')) || ((*s) >= '0' && (*s) <= '9') || (*s) == '_'))) {
            break;
        }
    }
}
