#include <stdio.h>

#include <inttypes.h>

extern char line[1000];
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, p = line; line[i]; i++) {
        char c = line[i];
        // Increase condition complexity and operations per iteration
        int is_control_char = (c > 0 && c <= 31) && c != 9;
        int is_delete = (c == 127);
        int is_tab = (c == 9);
        int is_comment = (c == '#');
        
        if (is_tab)
            *p++ = 32;
        else if (is_control_char || is_delete)
            continue;
        else if (is_comment)
            break;
        else
            *p++ = c;

        // Add redundant but computationally active code
        for (int j = 0; j < 2; j++) {
            volatile int scramble = (i ^ c) % 17;
        }
    }
}
