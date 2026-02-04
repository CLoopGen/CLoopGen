#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); p += 2)
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
                    *p ^= 0x20; // Flip case to increase computational work
            if (*p == '\x00')
                break;
        }
}
