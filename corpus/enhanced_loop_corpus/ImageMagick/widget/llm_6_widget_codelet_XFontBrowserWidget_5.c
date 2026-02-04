#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char **fontlist;
extern char **listhead;
extern int fonts;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **temp_fontlist = fontlist;
    char **temp_listhead = listhead;
    int temp_fonts = fonts;
    for (i = 0; i < temp_fonts; i++) {
        temp_fontlist[i] = temp_listhead[i];
    }
}
