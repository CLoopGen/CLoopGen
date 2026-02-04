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
    int local_brackets = in_brackets;
    char *local_p = p;

    for (;;) {
        char c = local_p[local_offset];
        int is_whitespace = (c == ' ' || c == '\t');
        int is_open_bracket = (c == '[');
        int is_close_bracket = (c == ']' && local_brackets);
        int is_valid_inside_brackets = (local_brackets && 
            (c == ':' || c == '.' || c == '-' || (c >= '0' && c <= '9')));

        if (is_whitespace) {
            local_offset++;
        } else if (is_open_bracket) {
            local_offset++;
            local_brackets++;
        } else if (is_close_bracket) {
            local_offset++;
            local_brackets--;
        } else if (is_valid_inside_brackets) {
            local_offset++;
        } else {
            break;
        }
    }

    offset = local_offset;
}
