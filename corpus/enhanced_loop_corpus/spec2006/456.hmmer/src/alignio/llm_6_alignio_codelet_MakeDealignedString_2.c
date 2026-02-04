#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int alen;
extern char *ss;
extern char *new;
extern int apos;
extern int rpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < alen; i++) {
        char current_char = aseq[i];
        int is_valid = !((current_char == ' ') || (current_char == '.') || 
                         (current_char == '_') || (current_char == '-') || 
                         (current_char == '~'));
        if (is_valid) {
            new[rpos] = ss[i];
            rpos++;
        }
    }
}
