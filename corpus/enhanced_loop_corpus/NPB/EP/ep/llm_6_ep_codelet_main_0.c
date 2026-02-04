#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    int i;
    for (i = 13; i >= 1; i--) {
        if (size[i] == '.')
            size[i] = ' ';
        size[0] = size[i]; // Introduce WAW and RAW dependency: write-after-write on size[0], read-after-write on size[i]
    }
}
