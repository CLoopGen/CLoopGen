#include <stdio.h>

#include <inttypes.h>

extern int gauge_dir;
extern int dir;
extern int ndir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int dir = indices[i];
        if (dir != gauge_dir)
            ndir++;
    }
}
