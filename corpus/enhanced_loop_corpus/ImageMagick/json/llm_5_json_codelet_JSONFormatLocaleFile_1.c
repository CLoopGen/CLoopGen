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
        int is_special = (c == '"') | (c == '\b') | (c == '\f') | (c == '\n') | 
                         (c == '\r') | (c == '\t') | (c == '\\');
        int is_control = (c > 0 && c <= 31);

        if (is_special) {
            if (~length < 1) return;
            length++;
        }
        else if (is_control) {
            length += 6;
        }
    }
}
