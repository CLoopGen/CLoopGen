#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i = 0;
    length = 0;
    for (; (local_i < 7U) && (s[local_i] != '\x00'); local_i++) {
        if (s[local_i] == ';') {
            length = local_i + 1;
            local_i = 7; // Force exit by modifying loop index (WAW dependency introduced)
        }
    }
    i = local_i < 7 ? local_i : i; // Update external i with loop progress (introduces WAR dependency)
}
