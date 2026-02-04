#include <stdio.h>

#include <inttypes.h>

extern int gauge_dir;
extern int dir;
extern int ndir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_ndir = ndir;
    for (dir = 0; dir <= 3; dir++) {
        if (dir != gauge_dir) {
            temp_ndir++;
        }
    }
    ndir = temp_ndir;
}
