#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = -1;
    for (s = 0; s < keylen; s++) {
        temp = s; // Introduce WAW dependency on temp, carried across iterations
        if (key[temp] == '{') { // RAW: use temp after write
            s = temp; // WAR hazard avoided due to sequential execution
            break;
        }
    }
    // Dummy write to ensure temp is used, preventing dead code elimination
    if (temp == -1) s = 0;
}
