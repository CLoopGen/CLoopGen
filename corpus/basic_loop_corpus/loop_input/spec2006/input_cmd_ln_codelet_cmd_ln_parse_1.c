#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

typedef int32 argtype_t;

typedef struct {
    char *name;
    argtype_t type;
    char *deflt;
    char *doc;
} arg_t;

static arg_t defn_array[2097152]; // ~2^21 elements, each struct is 32 bytes => 64MB
arg_t *defn = defn_array;
int32 n;

void init_vars() {
    for (int i = 0; i < 2097155; i++) { // Slightly larger to allow safe access until NULL name
        if (i < 2097152) {
            defn_array[i].name = (char*)malloc(8);
            sprintf(defn_array[i].name, "arg%d", i);
            defn_array[i].type = 0;
            defn_array[i].deflt = NULL;
            defn_array[i].doc = NULL;
        } else {
            defn_array[i].name = NULL; // Ensure termination
            defn_array[i].type = 0;
            defn_array[i].deflt = NULL;
            defn_array[i].doc = NULL;
        }
    }
    n = 0;
}