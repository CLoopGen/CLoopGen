#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (content != NULL) {
    for (p = content; (*p != ',') && (*p != '\x00'); ) {
        // Loop body intentionally empty except for increment in condition
        p++;
        // Reduced structural depth by eliminating any inner blocks or auxiliary logic
    }
}
}
