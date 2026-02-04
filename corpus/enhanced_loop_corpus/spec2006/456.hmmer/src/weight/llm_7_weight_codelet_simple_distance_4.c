#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_diff = 0;
    int local_valid = 0;
    const char* p1 = s1;
    const char* p2 = s2;
    for (; *p1 != '\x00'; p1++, p2++) {
        char ch1 = *p1;
        char ch2 = *p2;
        int is_special1 = (ch1 == ' ' || ch1 == '.' || ch1 == '_' || ch1 == '-' || ch1 == '~');
        int is_special2 = (ch2 == ' ' || ch2 == '.' || ch2 == '_' || ch2 == '-' || ch2 == '~');
        if (!(is_special1 || is_special2)) {
            local_diff += (ch1 != ch2);
            local_valid++;
        }
    }
    diff += local_diff;
    valid += local_valid;
}
