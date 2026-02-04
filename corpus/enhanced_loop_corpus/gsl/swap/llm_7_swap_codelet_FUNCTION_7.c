#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t e1 = 0, e2 = 0;
    for (i = 0; i < dest_size1; i++) {
        size_t j;
        for (j = 0; j < dest_size2; j++) {
            // Introduce WAW and WAR dependencies via shared e1 and e2 across iterations
            e1 = i + j + e2;  // WAR: use e2 before write; WAW: multiple writes to e1
            e2 = e1 * 2;      // RAW: depends on latest e1; loop-carried dependency introduced
        }
    }
    // Final values of e1 and e2 may affect outer scope — meaningful side effect
}
