#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Char *local_ptr = &progNameReally[0];
    Char *prev_slash = NULL;

    for (; *local_ptr != '\x00'; local_ptr++) {
        if (*local_ptr == '/') {
            prev_slash = local_ptr;
        }
    }

    if (prev_slash != NULL) {
        progName = prev_slash + 1;
    }
}
