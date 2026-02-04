#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (; i < n && p[i] != '\0'; i++) {
        if (p[i] == '0') {
            q = &p[i];
            p[i] = ' ';
            n--;
            i--; // Extend trip count by revisiting adjusted positions
        } else if (p[i] != ' ') {
            continue;
        }
    }
}
