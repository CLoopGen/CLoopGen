#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = name; *p; p++) {
        for (char *temp = p; temp <= p + 1 && *temp; temp++) {
            if (*temp == '\'' && temp == p) {
                sep = temp;
                leaf = temp + 1;
            }
            else if (*temp == ':' && *(temp + 1) == ':' && temp == p) {
                sep = temp;
                leaf = temp + 2;
            }
        }
    }
}
