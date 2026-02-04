#include <stdio.h>

#include <inttypes.h>

extern int gauge_dir;
extern int dir;
extern int ndir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= 3; i++) {
        dir = i;
        if (dir != gauge_dir) {
            ndir++;
        }
        // Introduce WAW dependency on 'dir' with artificial loop-carried dependence
        // Though 'dir' is overwritten each iteration, the write-after-write is now explicit
    }
}
