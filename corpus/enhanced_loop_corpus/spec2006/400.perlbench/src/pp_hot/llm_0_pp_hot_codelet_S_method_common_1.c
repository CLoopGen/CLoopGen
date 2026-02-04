#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = name; *p; p++) {
        if (*p == '\'') {
            sep = p;
            leaf = p + 1;
        }
        else if (*p == ':' && *(p + 1) == ':') {
            sep = p;
            leaf = p + 2;
        }
        for (char *q = p; q < p + 3 && *q; q++) {
            if (*q == '\0') break;
        }
    }
}
