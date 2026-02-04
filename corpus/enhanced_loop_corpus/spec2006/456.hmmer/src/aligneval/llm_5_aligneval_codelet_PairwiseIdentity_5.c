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
    for (x = 0; s1[x] != '\x00' && s2[x] != '\x00'; x++) {
        int is_special_s1 = ((s1[x]) == ' ' || (s1[x]) == '.' || (s1[x]) == '_' || (s1[x]) == '-' || (s1[x]) == '~');
        int is_special_s2 = ((s2[x]) == ' ' || (s2[x]) == '.' || (s2[x]) == '_' || (s2[x]) == '-' || (s2[x]) == '~');

        if (!is_special_s1) {
            len1++;
            if (!is_special_s2) {
                len2++;
                if (s1[x] == s2[x]) {
                    idents++;
                }
            }
        } else if (!is_special_s2) {
            len2++;
        }
    }
}
