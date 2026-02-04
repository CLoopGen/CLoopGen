#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s + 2;
    int local_level = level;
    for (; *temp && local_level; temp++) {
        if (*temp == '(') {
            local_level++;
        } else if (*temp == ')') {
            local_level--;
        }
    }
    level = local_level;
}
