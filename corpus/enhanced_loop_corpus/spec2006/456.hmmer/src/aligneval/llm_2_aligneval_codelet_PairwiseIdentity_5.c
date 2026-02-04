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
    // Variant 1: Strided memory access with stride of 2
    for (x = 0; s1[x] != '\x00' && s2[x] != '\x00'; x += 2) {
        if (!((s1[x]) == ' ' || (s1[x]) == '.' || (s1[x]) == '_' || (s1[x]) == '-' || (s1[x]) == '~')) {
            len1++;
            if (x < len1 && s1[x] == s2[x])
                idents++;
        }
        if (!((s2[x]) == ' ' || (s2[x]) == '.' || (s2[x]) == '_' || (s2[x]) == '-' || (s2[x]) == '~'))
            len2++;
    }
    // Handle odd-indexed elements in a second pass to maintain correctness
    for (int i = 1; s1[i] != '\x00' && s2[i] != '\x00'; i += 2) {
        if (!((s1[i]) == ' ' || (s1[i]) == '.' || (s1[i]) == '_' || (s1[i]) == '-' || (s1[i]) == '~')) {
            len1++;
            if (s1[i] == s2[i])
                idents++;
        }
        if (!((s2[i]) == ' ' || (s2[i]) == '.' || (s2[i]) == '_' || (s2[i]) == '-' || (s2[i]) == '~'))
            len2++;
    }
}
