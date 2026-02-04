#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *out_funcname;
extern int j;
extern char *sha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 40; j++) {
        int offset = 'a' - 'A';
        char current_char = sha[j];
        int is_uppercase = (current_char >= 'A') & (current_char <= 'Z');
        out_funcname[j + 2] = is_uppercase ? (current_char + offset) : current_char;
    }
}
