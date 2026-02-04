#include <stdio.h>

#include <inttypes.h>

extern int gauge_dir;
extern int dir;
extern int ndir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++)
        for (dir = 0; dir <= 3; dir++)
            if (dir != gauge_dir)
                ndir++;
}
