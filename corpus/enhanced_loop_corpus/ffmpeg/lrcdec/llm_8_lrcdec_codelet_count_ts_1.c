#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern int64_t offset;
extern int in_brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_offset = offset;
    int local_in_brackets = in_brackets;
    char* local_p = p;

    // Unroll the loop by a factor of 2 to reduce branch checks per iteration
    while (1) {
        if (local_p[local_offset] == ' ' || local_p[local_offset] == '\t') {
            local_offset++;
        } else if (local_p[local_offset] == '[') {
            local_offset++;
            local_in_brackets++;
        } else if (local_p[local_offset] == ']' && local_in_brackets) {
            local_offset++;
            local_in_brackets--;
        } else if (local_in_brackets && (local_p[local_offset] == ':' || local_p[local_offset] == '.' || 
                                        local_p[local_offset] == '-' || 
                                        (local_p[local_offset] >= '0' && local_p[local_offset] <= '9'))) {
            local_offset++;
        } else {
            break;
        }

        // Second unrolled iteration
        if (local_p[local_offset] == ' ' || local_p[local_offset] == '\t') {
            local_offset++;
        } else if (local_p[local_offset] == '[') {
            local_offset++;
            local_in_brackets++;
        } else if (local_p[local_offset] == ']' && local_in_brackets) {
            local_offset++;
            local_in_brackets--;
        } else if (local_in_brackets && (local_p[local_offset] == ':' || local_p[local_offset] == '.' || 
                                        local_p[local_offset] == '-' || 
                                        (local_p[local_offset] >= '0' && local_p[local_offset] <= '9'))) {
            local_offset++;
        } else {
            break;
        }
    }

    offset = local_offset;
    in_brackets = local_in_brackets;
}
