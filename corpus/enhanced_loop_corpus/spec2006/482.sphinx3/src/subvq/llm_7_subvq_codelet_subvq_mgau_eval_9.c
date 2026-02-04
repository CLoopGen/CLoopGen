#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *active;
extern int32 i;
extern int32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_c;
    for (i = 0; active[i] >= 0; i++) {
        local_c = active[i]; // Eliminate loop-carried dependency by using a local variable
        c = local_c;         // Write to c only in this scope, no carry-over between iterations
    }
}
