#include <stdio.h>

#include <inttypes.h>

extern int gauge_dir;
extern int dir;
extern int ndir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dir = 0; dir < 8; dir += 2) {
        if ((dir ^ gauge_dir) != 0)
            ndir++;
    }
}
