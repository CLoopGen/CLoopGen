#include <stdio.h>

extern int j;
extern char size[14];

void loop(){
for (j = 13; j >= 1; j--) {
    if (size[j] == '.')
        size[j] = ' ';
}

}
