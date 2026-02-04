#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c1, c2;
    for (; *s1 != '\x00'; ) {
        c1 = *s1;
        c2 = *s2;
        s1++;
        s2++;
        if (((c1) == ' ' || (c1) == '.' || (c1) == '_' || (c1) == '-' || (c1) == '~') || 
            ((c2) == ' ' || (c2) == '.' || (c2) == '_' || (c2) == '-' || (c2) == '~'))
            continue;
        if (c1 != c2)
            diff++;
        valid++;
    }
}
