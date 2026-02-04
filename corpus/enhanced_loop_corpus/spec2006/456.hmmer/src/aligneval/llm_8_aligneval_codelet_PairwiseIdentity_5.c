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
    for (x = 0; s1[x] != '\x00' && s2[x] != '\x00'; x += 2) {
        for (i = 0; i < 2; i++) {
            if (s1[x + i] == '\x00' || s2[x + i] == '\x00') break;
            if (!((s1[x + i]) == ' ' || (s1[x + i]) == '.' || (s1[x + i]) == '_' || (s1[x + i]) == '-' || (s1[x + i]) == '~')) {
                len1++;
                if (s1[x + i] == s2[x + i])
                    idents++;
            }
            if (!((s2[x + i]) == ' ' || (s2[x + i]) == '.' || (s2[x + i]) == '_' || (s2[x + i]) == '-' || (s2[x + i]) == '~'))
                len2++;
        }
    }
}
