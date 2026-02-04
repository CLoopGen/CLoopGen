#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    end = url;
    for (; *end != '\x00' && *(end + 1) != '\x00'; end += 2) {
        if (*end == ' ' || *(end + 1) == ' ') {
            if (*end == ' ') end += 0; // Keep end pointing to the space
            else end += 1;
            break;
        }
    }
    // Handle case where we might have skipped the last character
    if (*end == '\x00' && *(end - 1) != '\x00' && *(end - 1) == ' ' && end == url + 1)
        end = url;
}
