#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs long enough
    // but terminates safely. We aim for approximately 1MB of effective data,
    // so we replicate the 4KB buffer multiple times in logic, but since the array
    // is fixed at 4096 bytes, we design the content to cause the loop to iterate
    // many times by using nested structures.

    // To increase execution time within the constraints of a 4KB buffer,
    // we fill it with many '(' and ')' pairs, forcing the inner loop to run frequently.
    int i = 0;
    int len = 4096;
    int chunk = 8; // Each chunk: "abc(defg" -> '(' every 4-8 chars

    for (i = 0; i < len - 10; i += chunk) {
        if (i + 8 < len) {
            start_color[i] = 'a';
            start_color[i+1] = 'b';
            start_color[i+2] = 'c';
            start_color[i+3] = '(';
            start_color[i+4] = 'd';
            start_color[i+5] = 'e';
            start_color[i+6] = 'f';
            start_color[i+7] = ')';
            start_color[i+8] = 'g';
            chunk = 8;
        } else {
            break;
        }
    }

    // Fill remaining space with safe characters
    while (i < len - 1) {
        start_color[i++] = 'x';
    }
    start_color[len - 1] = '-'; // Ensure termination condition near the end

    // Reset p to start for the loop
    p = start_color;
}