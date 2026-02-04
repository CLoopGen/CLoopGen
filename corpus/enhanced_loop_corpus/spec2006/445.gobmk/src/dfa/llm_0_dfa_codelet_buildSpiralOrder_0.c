#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 21; k++)
                for (int l = 0; l < 4; l++)
                    mark[i * 4 * 21 * 4 + j * 21 * 4 + k * 4 + l] = 1;
}
