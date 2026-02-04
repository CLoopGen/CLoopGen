#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures realistic traversal
    // including parentheses and avoiding premature null terminators
    for (int i = 0; i < 4095; i++) {
        if (i % 128 == 0 && i + 10 < 4095) {
            // Insert balanced parentheses groups occasionally
            start_color[i] = '(';
            int j;
            for (j = 1; j < 10 && (i + j) < 4095; j++) {
                start_color[i + j] = 'a' + (j % 26);
            }
            start_color[i + j] = ')';
            i += j;
        } else if (i % 64 == 0) {
            // Insert '-' occasionally to allow loop exit condition
            start_color[i] = '-';
            // But ensure it's not too early — skip over next few positions
            i++;
        } else {
            // Fill with random letters, avoiding '\0' and '-' most of the time
            start_color[i] = 'a' + (i % 26);
        }
    }
    // Ensure last character is null terminator
    start_color[4095] = '\0';
}