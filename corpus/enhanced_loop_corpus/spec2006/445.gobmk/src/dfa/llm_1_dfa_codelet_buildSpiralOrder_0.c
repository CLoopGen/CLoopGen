#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 84; i++)
        for (int j = 0; j < 84; j++)
            if (i * 84 + j < 21 * 4 * 21 * 4)
                mark[i * 84 + j] = 1;
}
