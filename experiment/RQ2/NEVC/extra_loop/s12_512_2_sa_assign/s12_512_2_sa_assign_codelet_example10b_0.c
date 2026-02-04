#include <stdio.h>

extern short *restrict sa;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 512; i += 2) {
    assign[i] = (int)sa[i];
}

}
