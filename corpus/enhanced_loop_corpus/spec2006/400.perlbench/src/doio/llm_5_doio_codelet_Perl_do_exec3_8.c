#include <stdio.h>

#include <inttypes.h>

extern char *cmd;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = cmd; *s; s++) {
        if ((*s >= 'A' && *s <= 'Z')) continue;
        if ((*s >= 'a' && *s <= 'z')) continue;
        if ((*s >= '0' && *s <= '9')) continue;
        if (*s == '_') continue;
        break;
    }
}
