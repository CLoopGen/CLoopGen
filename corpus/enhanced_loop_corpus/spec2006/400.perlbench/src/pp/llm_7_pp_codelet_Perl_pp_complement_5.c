#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long *local_tmpl = tmpl;
    I32 local_anum = anum;
    for (; local_anum >= sizeof(long); local_anum -= sizeof(long), local_tmpl++)
        *(local_tmpl) = ~*(local_tmpl); // Eliminate loop-carried WAW dependency by using local pointer; no cross-iteration write conflict
    tmpl = local_tmpl; // Update global tmpl only once after loop
}
