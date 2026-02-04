#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 0;
    while (s1[limit] != '\x00') limit++; // Precompute length to control trip count
    for (col = 0; col < limit && col < 256; col++) {
        char ch1 = s1[col];
        char ch2 = s2[col];
        int is_valid_char_s1 = (ch1 == ' ' || ch1 == '.' || ch1 == '_' || ch1 == '-' || ch1 == '~');
        int is_valid_char_s2 = (ch2 == ' ' || ch2 == '.' || ch2 == '_' || ch2 == '-' || ch2 == '~');

        if (!is_valid_char_s1) {
            // Increased arithmetic: use modulo and addition to increase computational load
            r2 = (r2 + 1 + (ch1 % 7)) % 10000;
            s1_list[r1] = is_valid_char_s2 ? -1 : (r2 * 3 + 7);
            r1++;
        }

        if (!is_valid_char_s2) {
            r2++;
        }
    }
}
