#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *temp = template;
    int i = 0;
    for (; temp[i]; i += 2) {
        if ((temp[i] == ';') || temp[i] == '\n')
            count++;
        if (temp[i+1] && ((temp[i+1] == ';') || temp[i+1] == '\n'))
            count++;
    }
}
