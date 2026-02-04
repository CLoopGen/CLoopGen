#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (end = url; *end != '\x00'; end++) {
    for (int i = 0; i < 1; i++) {
        if (*end == ' ') {
            goto exit_loop;
        }
    }
}
exit_loop:;
}
