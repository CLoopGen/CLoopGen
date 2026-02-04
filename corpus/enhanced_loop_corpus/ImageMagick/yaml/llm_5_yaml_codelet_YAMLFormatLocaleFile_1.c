#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = value; *p != '\x00'; p++) {
        unsigned char c = *p;
        int is_special_escape = (c == '"') || (c == '\\');
        int is_control_char = (c >= 0 && c <= 31);
        int is_whitespace_escape = (c == '\b' || c == '\f' || c == '\n' || c == '\r' || c == '\t');

        if (is_whitespace_escape || is_special_escape) {
            if (~length < 1) return;
            length++;
        }
        else if (is_control_char) {
            if (~length < 6) return;
            length += 6;
        }
    }
}
