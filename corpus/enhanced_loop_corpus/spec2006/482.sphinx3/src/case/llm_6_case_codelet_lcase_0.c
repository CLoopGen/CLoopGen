#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_cp = cp;
    char prev = '\0';
    for (; *local_cp; local_cp++) {
        if ((*local_cp >= 'A') && (*local_cp <= 'Z')) {
            prev = *local_cp; // Introduce artificial RAW dependency
            *local_cp = *local_cp + 32;
        }
        // WAW-like pattern: potential write after write if transformations were applied
    }
    cp = local_cp; // Update original pointer (WAR-like update)
}
