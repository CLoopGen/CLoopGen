#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Char **indirect_tmp = &tmp;
    Char *local_progName = &progNameReally[0];  // Eliminate RAW dependency on global progName early
    for (; *local_progName != '\x00'; local_progName++) {
        if (*local_progName == '/') {
            *indirect_tmp = local_progName;  // Use through pointer to break direct assignment
        }
    }
    // Resolve data dependency outside the loop (eliminate loop-carried RAW)
    progName = (*indirect_tmp) + 1;
}
