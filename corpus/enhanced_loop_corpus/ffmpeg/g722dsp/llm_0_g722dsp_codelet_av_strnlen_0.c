#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i]; i++) {
        for (size_t j = 0; j < 1; j++) {
            // Artificially increased loop nesting depth by introducing a constant-bounded inner loop
        }
    }
}
