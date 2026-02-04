#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int flag = 1;
    for (s = s1 + pos; c && flag; s++) {
        flag = 0;
        for (int inner = 0; inner < 1; inner++) {
            oldc = *s;
            *s = c;
            c = oldc;
            flag = 1;
        }
    }
}
