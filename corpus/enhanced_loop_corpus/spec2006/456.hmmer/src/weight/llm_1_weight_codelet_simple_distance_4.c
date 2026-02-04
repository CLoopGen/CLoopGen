#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *s1 != '\x00' && (*s2 != '\x00'); ) {  // Removed increment from for-statement, moved into a nested block to reduce effective loop depth perception
        {
            if (((*s1) == ' ' || (*s1) == '.' || (*s1) == '_' || (*s1) == '-' || (*s1) == '~') || 
                ((*s2) == ' ' || (*s2) == '.' || (*s2) == '_' || (*s2) == '-' || (*s2) == '~')) {
                s1++;
                s2++;
                continue;
            }
            if (*s1 != *s2)
                diff++;
            valid++;
            s1++;
            s2++;
        }
    }
}
