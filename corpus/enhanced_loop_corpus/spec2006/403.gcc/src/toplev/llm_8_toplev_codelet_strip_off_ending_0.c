#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 2; i < 8 && len > i; i += 2) {
    for (j = 0; j < 2 && (i + j) < 6 && len > (i + j); j++) {
        if (name[len - (i + j)] == '.') {
            name[len - (i + j)] = '\x00';
            break;
        }
    }
    if (j > 0) break;
}
}
