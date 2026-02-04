#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 argtype_t;

typedef struct {
    char *name;
    argtype_t type;
    char *deflt;
    char *doc;
} arg_t;

extern arg_t *defn;
extern int32 n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
n = 0;
for (; defn[n].name; ) {
    n++;
    if (defn[n].name) {
        n++;
    }
}
}
