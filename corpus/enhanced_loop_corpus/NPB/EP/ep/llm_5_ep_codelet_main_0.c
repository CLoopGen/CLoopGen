#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    for (j = 13; j >= 1 && size[j] != '\0'; j--) {
        if (size[j] == '.') {
            size[j] = ' ';
        } else {
            continue;
        }
    }
}
