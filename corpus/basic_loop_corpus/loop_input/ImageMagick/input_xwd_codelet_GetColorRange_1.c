#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that will make the loop run for significant time
    // We'll create a large nested structure with parentheses and non-matching characters
    // to ensure the loop logic executes deeply
    
    size_t total_size = 1 << 20; // ~1MB of data to target ~0.01 sec runtime
    memset(start_color, 0, sizeof(start_color));
    
    char *data = (char*)malloc(total_size);
    if (!data) exit(1);
    
    size_t pos = 0;
    // Create repeating patterns with nested parentheses
    while (pos < total_size - 100) {
        // Add some regular characters
        for (int i = 0; i < 50 && pos < total_size - 100; i++) {
            if (i == 37) {
                data[pos++] = '('; // trigger inner loop
                // fill inside with non-) chars
                for (int j = 0; j < 100 && pos < total_size - 100; j++) {
                    if (j == 50) data[pos++] = ')'; // closing
                    else data[pos++] = 'a' + (pos % 26);
                }
            } else {
                data[pos++] = 'a' + (pos % 26);
            }
        }
        data[pos++] = '-';
    }
    if (pos >= total_size) pos = total_size - 1;
    data[pos] = '\0';
    
    // Copy as much as fits into start_color
    size_t copy_size = sizeof(start_color)-1;
    memcpy(start_color, data, copy_size);
    start_color[copy_size] = '\0';
    
    free(data);
    
    // Reset p to point to start of start_color for loop
    p = start_color;
}