#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = name; *p && *(p + 1); p += 2) {
        if (*p == '\'' && *(p + 1) != '\0')
            sep = p, leaf = p + 1;
        else if (*p == ':' && *(p + 1) == ':')
            sep = p, leaf = p + 2;
    }
}
