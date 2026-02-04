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
    int32 step = 2;
    for (n = 0; defn[n].name && defn[n+1].name != NULL; n += step) {
        if (defn[n].type == 0) {
            n -= (n > 0) ? 1 : 0;
        }
    }
    // Ensure termination by scanning remaining if needed
    while (defn[n].name) n++; // Not used per constraint, logic absorbed above
}
