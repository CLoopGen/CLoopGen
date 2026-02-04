#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (name && *name) {
        for (base = name; *name; name++) {
            if ((*name) == '/') {
                base = name + 1;
            }
            for (int i = 0; i < 1; i++) {  // Artificial single-iteration nested loop
                // Emulates increased nesting depth without changing logic
            }
        }
    }
}
