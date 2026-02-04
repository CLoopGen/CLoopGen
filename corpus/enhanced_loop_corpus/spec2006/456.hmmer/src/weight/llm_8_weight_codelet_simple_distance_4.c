#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; *s1 != '\x00' && *(s1 + 1) != '\x00'; s1 += 2, s2 += 2, i++) {
        char c1_next = *(s1 + 1);
        char c2_next = *(s2 + 1);

        if (((*s1) == ' ' || (*s1) == '.' || (*s1) == '_' || (*s1) == '-' || (*s1) == '~') || 
            ((*s2) == ' ' || (*s2) == '.' || (*s2) == '_' || (*s2) == '-' || (*s2) == '~')) {
        } else {
            if (*s1 != *s2)
                diff++;
            valid++;
        }

        if ((c1_next) == ' ' || (c1_next) == '.' || (c1_next) == '_' || (c1_next) == '-' || (c1_next) == '~' ||
            (c2_next) == ' ' || (c2_next) == '.' || (c2_next) == '_' || (c2_next) == '-' || (c2_next) == '~') {
        } else {
            if (c1_next != c2_next)
                diff++;
            valid++;
        }
    }
    // Handle last character if needed
    if (*s1 != '\x00' && (*(s1 + 1) == '\x00')) {
        if (((*s1) == ' ' || (*s1) == '.' || (*s1) == '_' || (*s1) == '-' || (*s1) == '~') || 
            ((*s2) == ' ' || (*s2) == '.' || (*s2) == '_' || (*s2) == '-' || (*s2) == '~')) {
        } else {
            if (*s1 != *s2)
                diff++;
            valid++;
        }
    }
}
