#include <stdio.h>

#include <inttypes.h>

extern int gauge_dir;
extern int dir;
extern int ndir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dir = 0; dir <= 3; dir++) {
        for (int inner = 0; inner < 1; inner++) {
            if (dir != gauge_dir)
                ndir++;
        }
    }
}
