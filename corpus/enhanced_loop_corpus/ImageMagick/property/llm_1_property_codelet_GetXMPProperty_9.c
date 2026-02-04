#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *xmp_profile;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = xmp_profile; *p != '\x00'; p++) {
        for (int offset = 0; offset < 2; offset++) {
            if ((*(p + offset) == '<') && (*(p + offset + 1) == 'x')) {
                p += offset;
                goto exit_loop;
            }
        }
    }
exit_loop:;
}
