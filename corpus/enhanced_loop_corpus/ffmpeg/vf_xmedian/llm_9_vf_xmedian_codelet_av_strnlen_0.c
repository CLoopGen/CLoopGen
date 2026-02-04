#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every 4th element, but still terminate on null or bounds
    for (i = 0; i < len && s[i]; i += 4) {
        // Maintain correctness: check if any of the skipped positions is null
        size_t offset;
        for (offset = 1; offset < 4 && (i + offset) < len; offset++) {
            if (!s[i + offset]) {
                i += offset;
                goto end_loop;
            }
        }
    }
end_loop:
    ;
}
