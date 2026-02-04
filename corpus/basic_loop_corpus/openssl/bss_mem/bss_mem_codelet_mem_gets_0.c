#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < j; i++) {
    if (p[i] == '\n') {
        i++;
        break;
    }
}

}
