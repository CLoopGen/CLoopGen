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



void loop() {
    int32 i;
    argtype_t temp_type = 0;
    for (i = 0; defn[i].name != NULL; i++) {
        temp_type = defn[i].type;  // Introduce temporary to create WAW and RAW dependencies
        defn[i].type = temp_type;  // Write after write on defn[i].type (WAW)
    }
    n = i;  // Store final count to original variable, creating loop-carried dependency on i
}
