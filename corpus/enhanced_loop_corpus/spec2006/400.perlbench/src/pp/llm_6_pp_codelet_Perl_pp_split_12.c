#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s;
    for (m = s; temp < strend && *temp != c; temp++) {
        m = temp + 1;
    }
    if (temp >= strend || *temp == c) {
        m = temp;
    }
}
