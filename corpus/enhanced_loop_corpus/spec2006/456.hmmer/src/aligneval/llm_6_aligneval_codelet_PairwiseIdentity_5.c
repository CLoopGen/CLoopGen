#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int idents;
extern int len1;
extern int len2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; s1[i] != '\x00' && s2[i] != '\x00'; i++) {
        char c1 = s1[i];
        char c2 = s2[i];
        int is_special1 = (c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~');
        int is_special2 = (c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~');
        
        if (!is_special1) {
            len1++;
            if (c1 == c2)
                idents++;
        }
        if (!is_special2) {
            len2++;
        }
        x = i; // WAW dependency introduced: x is updated each iteration, creating loop-carried WAW
    }
}
