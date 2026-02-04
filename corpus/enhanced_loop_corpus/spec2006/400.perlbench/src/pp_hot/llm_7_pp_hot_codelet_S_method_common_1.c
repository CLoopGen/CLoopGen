#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = name;
    char *local_sep = sep;
    char *local_leaf = leaf;

    for (int i = 0; local_p[i]; i++) {
        if (local_p[i] == '\'') {
            local_sep = &local_p[i];
            local_leaf = &local_p[i] + 1;
        }
        else if (local_p[i] == ':' && local_p[i + 1] == ':') {
            local_sep = &local_p[i];
            local_leaf = &local_p[i] + 2;
        }
    }

    sep = local_sep;
    leaf = local_leaf;
}
