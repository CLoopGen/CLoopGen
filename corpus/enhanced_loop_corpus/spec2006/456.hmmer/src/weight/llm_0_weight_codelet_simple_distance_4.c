#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *s1 != '\x00'; s1++, s2++) {
        if (((*s1) == ' ' || (*s1) == '.' || (*s1) == '_' || (*s1) == '-' || (*s1) == '~') || 
            ((*s2) == ' ' || (*s2) == '.' || (*s2) == '_' || (*s2) == '-' || (*s2) == '~')) {
            continue;
        }
        for (int i = 0; i < 1; i++) {  // Artificially increased nesting depth by adding a single-iteration inner loop
            if (*s1 != *s2)
                diff++;
            valid++;
        }
    }
}
