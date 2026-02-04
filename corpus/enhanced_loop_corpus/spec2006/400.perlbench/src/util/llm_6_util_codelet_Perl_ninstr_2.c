#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *temp_s = little;
    char *temp_x = big;
    char prev_char = '\0';
    
    for (; temp_s < littleend; ) {
        char s_val = *temp_s;
        char x_val = *temp_x;
        if (s_val != x_val) {
            temp_s--;
            break;
        }
        prev_char = s_val;
        temp_s++;
        temp_x++;
    }
    s = temp_s;
    x = temp_x;
}
