#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    for (int i = 13; i >= 1; i--) {
        for (j = i; j >= 1; j--) {
            if (size[j] == '.')
                size[j] = ' ';
        }
    }
}
