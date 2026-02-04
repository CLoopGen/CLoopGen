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
    int step = 1;
    for (x = 0; s1[x] != '\x00' && s2[x] != '\x00'; x += step) {
        char c1 = s1[x], c2 = s2[x];
        int isSpecial1 = (c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~');
        int isSpecial2 = (c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~');
        
        if (!isSpecial1) {
            len1++;
            if (c1 == c2)
                idents++;
        }
        if (!isSpecial2)
            len2++;
        
        step = (c1 % 2) + 1; // Vary step size based on character value to alter effective trip count and intensity
    }
}
