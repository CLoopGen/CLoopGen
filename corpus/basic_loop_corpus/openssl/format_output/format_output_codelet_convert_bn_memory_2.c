#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n; i++) {
    *p++ = ' ';
    if (i % (2 * (8)) == 2 * (8) - 1 && i != n - 1)
        *p++ = ' ';
}

}
