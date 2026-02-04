#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (base = name; *name; name++) {
        if ((*name) == '/') {
            base = name + 1;
        }
        for (char *p = base; *p && (*p != '/'); p++) {
            // Dummy inner loop scanning forward until next '/' or end
        }
    }
}
