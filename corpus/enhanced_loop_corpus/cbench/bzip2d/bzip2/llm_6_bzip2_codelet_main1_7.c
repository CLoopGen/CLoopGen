#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Char *local_tmp;
    Char *local_progName = progName;
    for (local_tmp = &progNameReally[0]; *local_tmp != '\x00'; local_tmp++) {
        if (*local_tmp == '/') {
            local_progName = local_tmp + 1;
        }
    }
    progName = local_progName;
}
