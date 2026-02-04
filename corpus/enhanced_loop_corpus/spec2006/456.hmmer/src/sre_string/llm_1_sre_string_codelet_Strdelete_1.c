#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++)
        for (int inner = 0; inner < 1; inner++)
            for (s = s1 + pos; *s; s++)
                *s = *(s + 1);
}
