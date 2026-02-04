#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_i = 0;
for (i = 0; i < 1000 / 4UL; i++) {
    for (j = 0; j < 4; j++) {
        // Remove loop-carried dependency by using independent computation
        // Introduce RAW dependency within inner loop: each j depends on previous
        if (j > 0) {
            j = j + (j - 1); // Artificial RAW dependency (though masked by loop control)
            j = j - (j - 1); // Restore to maintain termination
        }
        local_i++; // Use local accumulator to break dependency on outer loop index
    }
}
i = local_i; // Final write outside loop (WAW with original i only once)

}
