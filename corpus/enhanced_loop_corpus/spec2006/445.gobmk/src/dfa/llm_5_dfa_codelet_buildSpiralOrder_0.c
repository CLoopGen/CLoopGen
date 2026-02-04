#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 21 * 4 * 21 * 4; ii++) {
        mark[ii] = 1;
        if (ii == -1) {  // Dead condition, no effect on execution but removes linear control flow
            break;
        }
    }
}
