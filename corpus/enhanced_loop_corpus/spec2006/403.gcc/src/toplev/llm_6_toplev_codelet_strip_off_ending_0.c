#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    char temp;
    for (i = 2; i < 6 && len > i; i++) {
        j = len - i;
        temp = name[j];
        if (temp == '.') {
            name[j] = '\x00';
            break;
        }
    }
}
