#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    int start = 13;
    int end = 1;
    for (j = start; j >= end; j -= 2) {
        if (size[j] == '.')
            size[j] = ' ';
        if (j - 1 >= end && size[j - 1] == '.')
            size[j - 1] = ' ';
    }
}
