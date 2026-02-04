#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (base = name; *name; name++) {
        if (*name == '/') {
            base = name + 1;
        } else {
            // Different execution path: do nothing, but maintain control structure
        }
    }
}
