#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that will cause the loop to run for significant time
    // We'll create a large nested structure with many '(' and ')' pairs to ensure deep traversal
    // The array is 4096 bytes as per declaration
    
    size_t total_size = sizeof(start_color);
    char *data = start_color;
    
    // Fill most of the buffer with open parentheses followed by non-matching content
    // This forces the inner loop to scan until it finds ')'
    size_t pos = 0;
    while (pos < total_size - 64) {
        if (pos + 10 < total_size) {
            data[pos] = '(';
            pos++;
            // Fill inside with non-) characters
            int len = (total_size - pos - 10) > 100 ? 50 : (total_size - pos - 2);
            for (int i = 0; i < len; i++) {
                if (pos >= total_size - 1) break;
                if (i == len - 1) 
                    data[pos] = 'x'; // avoid null or '-' early
                else 
                    data[pos] = 'a' + (pos % 26);
                pos++;
            }
            // Close the group
            if (pos < total_size) {
                data[pos] = ')';
                pos++;
            }
        } else {
            break;
        }
    }
    
    // Ensure last part doesn't have unclosed parenthesis
    while (pos < total_size - 1) {
        data[pos] = 'x';
        pos++;
    }
    // Null terminate at the very end
    data[total_size - 1] = '\0';
    
    // Reset p to start for initial state
    p = start_color;
}