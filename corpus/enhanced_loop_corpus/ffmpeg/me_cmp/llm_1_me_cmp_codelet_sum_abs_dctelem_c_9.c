#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 4; depth1++)
        for (int depth2 = 0; depth2 < 4; depth2++)
            for (int depth3 = 0; depth3 < 4; depth3++)
                for (int depth4 = 0; depth4 < 4; depth4++)
                    sum += ((block[depth1 * 16 + depth2 * 4 + depth3 * 1 + depth4]) >= 0 ? 
                            (block[depth1 * 16 + depth2 * 4 + depth3 * 1 + depth4]) : 
                            (-(block[depth1 * 16 + depth2 * 4 + depth3 * 1 + depth4])));

}
