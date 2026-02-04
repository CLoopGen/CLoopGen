#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < m; i++) {
        temp += i * i;
    }
    // Introduce a reduction-style data dependency (WAW on temp, RAW on i)
    // Loop-carried dependence on temp removed by reinitializing outside
}
