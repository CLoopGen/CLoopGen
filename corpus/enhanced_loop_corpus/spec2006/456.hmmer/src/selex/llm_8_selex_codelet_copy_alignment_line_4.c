#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < lcol * 2; i += 2) {
    if (*s2) {
        for (j = 0; j < 3; j++) {
            s2++;
        }
    }
}
}
