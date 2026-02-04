#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    for (j = 13; j >= 0; j--) {
        if (j < 14 && size[j] == '.')
            size[j] = ' ';
    }
}
