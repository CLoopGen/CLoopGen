#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char found = 0;
    for (end = url; *end != '\x00' && !found; end++)
        found = (*end == ' ');
    if (found) end--;
}
