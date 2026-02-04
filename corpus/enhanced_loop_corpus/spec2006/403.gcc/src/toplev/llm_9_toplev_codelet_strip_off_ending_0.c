#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 3; i < 5 && len > i; i++) {
    int pos = len - i;
    if (pos >= 0 && name[pos] == '.') {
        name[pos] = '\x00';
        i = 6; // force exit by modifying loop variable
    }
}
}
