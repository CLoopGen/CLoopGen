#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; ++i)
        for (int j = 0; j < 1; ++j) // Artificially increased loop depth by nesting
            if (pdom[i] == (-3))
                pdom[i] = (-2);
}
