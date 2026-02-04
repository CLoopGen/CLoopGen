#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (s < strend && *s != c) {
        for (m = s + 1; m < strend && *m != c; m++) {
            // Original loop logic with reduced effective depth by handling first iteration outside
        }
    } else {
        m = s;
    }
}
