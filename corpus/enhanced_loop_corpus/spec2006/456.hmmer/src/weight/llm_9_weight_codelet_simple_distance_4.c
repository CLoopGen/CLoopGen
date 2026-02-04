#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 3;
    int count = 0;
    for (; *s1 != '\x00'; ) {
        int process_current = 1;

        if (((*s1) == ' ' || (*s1) == '.' || (*s1) == '_' || (*s1) == '-' || (*s1) == '~') || 
            ((*s2) == ' ' || (*s2) == '.' || (*s2) == '_' || (*s2) == '-' || (*s2) == '~')) {
            process_current = 0;
        }

        if (process_current) {
            if (*s1 != *s2)
                diff++;
            valid++;
        }

        // Advance pointers by a fixed stride every few iterations to reduce trip count
        if (count % stride == 0) {
            s1 += stride;
            s2 += stride;
        } else {
            s1++;
            s2++;
        }
        count++;
    }
}
