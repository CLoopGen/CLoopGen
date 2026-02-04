#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *source;
extern size_t *length;
extern wchar_t *utf16;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (ssize_t)*length; i++) {
        utf16[i] = source[i];
        if (source[i] == 0) {
            break; // Terminate early on encountering null byte
        }
    }
}
