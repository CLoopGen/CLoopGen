#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (apos = 0; apos < count2; apos++) {
        int is_valid = 1;
        char c = buf2[apos];
        if (c == ' ') is_valid = 0;
        if (c == '.') is_valid = 0;
        if (c == '_') is_valid = 0;
        if (c == '-') is_valid = 0;
        if (c == '~') is_valid = 0;
        if (is_valid) {
            rawcount2++;
        }
    }
}
