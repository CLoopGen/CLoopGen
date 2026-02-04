#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_len = len;
    char *local_s = s;
    for (i = 0; i < local_len && local_s[i]; i++) {
        // Introduce temporary local copies of global variables to create write-after-read
        // and remove potential aliasing or external dependencies.
        // This eliminates possible WAW and WAR hazards with external updates to 's' or 'len'.
        // Loop-carried dependency on 'i' remains, but memory access is now decoupled from globals.
    }
}
