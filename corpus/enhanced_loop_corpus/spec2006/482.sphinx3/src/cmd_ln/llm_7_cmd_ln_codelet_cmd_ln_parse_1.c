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
    int32 local_n = 0;
    const int32 stride = 1;
    for (; local_n < 1000; local_n += stride) {  // Eliminate data pointer dereference condition
        if (!defn[local_n].name) break;         // Check inside loop body instead
        n = local_n + 1;  // Update shared 'n' in each iteration — creates WAR dependency if used elsewhere
    }
}
