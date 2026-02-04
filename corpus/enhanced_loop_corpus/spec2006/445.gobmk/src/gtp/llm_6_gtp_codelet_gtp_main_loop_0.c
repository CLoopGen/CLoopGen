#include <stdio.h>

#include <inttypes.h>

extern char line[1000];
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = p;
    int temp_i;
    for (i = 0; line[i]; i++) {
        char c = line[i];
        if (c == 9) {
            temp_p[0] = 32;
            temp_p++;
        }
        else if ((c > 0 && c <= 9) || (c >= 11 && c <= 31) || c == 127)
            continue;
        else if (c == '#')
            break;
        else {
            temp_p[0] = c;
            temp_p++;
        }
    }
    p = temp_p;
}
