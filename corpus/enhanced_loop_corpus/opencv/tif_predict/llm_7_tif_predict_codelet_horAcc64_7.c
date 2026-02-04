#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t local_copy = stride;
    for (i = local_copy - 4; i > 0; i--) {
        *(volatile tmsize_t*)(&stride) = i; // Write to stride via volatile pointer to break reuse assumptions
    }
    // Eliminates potential WAW and WAR hazards on 'stride' by writing per iteration with side effect.
    // Loop-carried WAW dependency on memory location of 'stride' is introduced, but control uses a local copy.
    // Use of volatile prevents compiler from optimizing away writes, ensuring observable behavior.
}
