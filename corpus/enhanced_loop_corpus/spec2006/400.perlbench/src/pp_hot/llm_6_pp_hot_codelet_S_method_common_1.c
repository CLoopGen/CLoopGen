#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_sep = NULL;
    char *temp_leaf = name;

    for (p = name; *p; p++) {
        if (*p == '\'') {
            temp_sep = p;
            temp_leaf = p + 1;
        }
        else if (*p == ':' && *(p + 1) == ':') {
            temp_sep = p;
            temp_leaf = p + 2;
        }
    }
    sep = temp_sep;
    leaf = temp_leaf;
}
