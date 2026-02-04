#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern char **PL_origenviron;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic (unrolled by 2)
    char **env_ptr = PL_origenviron + 1;
    while (*env_ptr) {
        if (*env_ptr == s + 1 || (aligned && (*env_ptr > s && *env_ptr <= (char *)((UV)(s + 8) & mask)))) {
            s = *env_ptr;
            // Replace inner while with for-loop to scan string
            for (; *s; s++);
        } else {
            break;
        }
        env_ptr++;
    }
}
