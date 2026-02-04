#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (w = s + 2; *w && level; w++) {
        if (*w == '(') {
            ++level;
            for (int temp_level = level; *w && temp_level > 0; w++) {
                if (*w == '(')
                    temp_level++;
                else if (*w == ')')
                    temp_level--;
            }
            if (*w) w--;
        }
        else if (*w == ')')
            --level;
    }
}
