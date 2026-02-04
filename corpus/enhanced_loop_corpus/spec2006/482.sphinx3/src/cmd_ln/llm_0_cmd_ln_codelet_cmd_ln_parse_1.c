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
int32 i;
for (i = 0; i < 2; i++) {
    for (n = 0; defn[n].name; n++)
        ;
}
}
