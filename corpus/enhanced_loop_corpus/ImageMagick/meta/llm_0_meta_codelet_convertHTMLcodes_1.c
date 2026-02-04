#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 7U; i++) {
        if (s[i] == '\x00') break;
        for (size_t j = 0; j < 1; j++) {  // Artificially increased nesting depth
            if (s[i] == ';') {
                length = i + 1;
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
