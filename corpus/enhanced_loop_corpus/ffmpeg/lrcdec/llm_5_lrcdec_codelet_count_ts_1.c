#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern int64_t offset;
extern int in_brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        char c = p[offset];
        int is_whitespace = (c == ' ' || c == '\t');
        int is_open_bracket = (c == '[');
        int is_close_bracket = (c == ']' && in_brackets);
        int is_valid_in_brackets = (in_brackets && (c == ':' || c == '.' || c == '-' || (c >= '0' && c <= '9')));

        if (is_whitespace) {
            offset++;
        } else if (is_open_bracket) {
            offset++;
            in_brackets++;
        } else if (is_close_bracket) {
            offset++;
            in_brackets--;
        } else if (is_valid_in_brackets) {
            offset++;
        } else {
            break;
        }
    }
}
