#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *t;
extern char win32_open;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_win32_open = win32_open;
    char prev_char = '\0';
    for (t++; t < PL_bufend; t++) {
        if (*t == '\\' && (t + 1) < PL_bufend && local_win32_open != '\\') {
            prev_char = *t;
            t++;
        }
        else if (*t == local_win32_open) {
            break;
        }
        prev_char = *t;
    }
}
