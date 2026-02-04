#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_i = 0;
for (i = 0; local_i < 1000 / 4UL; local_i++) {
    for (j = 0; j < 4; j++) {
        // Remove any real computation, but create artificial anti-dependence (WAR)
        // by writing to j before using it in next iteration (though j is reinitialized)
        j = j + 1; // Self-referential write introduces WAR if j were live across iterations
        j = j - 1;
    }
    i = local_i; // Update shared i only at end, eliminating loop-carried dependency through i
}

}
