#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with data that will make the loop run for significant time
    // We'll create a pattern with nested parentheses and separators to exercise the loop logic
    size_t total_size = 1 << 20; // ~1MB of data to achieve ~0.01 sec runtime
    memset(start_color, 0, sizeof(start_color));
    
    char *data = (char*)malloc(total_size);
    if (!data) exit(1);
    
    size_t pos = 0;
    // Create repeating pattern: "abc(defg)hij-klm(nopq)rst-..."
    while (pos < total_size - 20) {
        // Add non-parenthesized segment
        memcpy(&data[pos], "abc", 3); pos += 3;
        
        // Add parenthesized segment
        if (pos + 8 < total_size) {
            memcpy(&data[pos], "(defg)", 6); pos += 6;
        }
        
        // Add more text
        memcpy(&data[pos], "hij", 3); pos += 3;
        
        // Add dash separator (loop terminator condition)
        if (pos < total_size) {
            data[pos++] = '-';
        }
        
        // Periodically break long sequences with nulls to ensure safety
        if (pos > total_size / 8 && (rand() % 200) == 0) {
            data[pos-1] = '\0';
        }
    }
    
    // Ensure last character is null terminator
    if (pos >= total_size) pos = total_size - 1;
    data[pos] = '\0';
    
    // Copy as much as fits into start_color
    size_t copy_size = sizeof(start_color) - 1;
    memcpy(start_color, data, copy_size);
    start_color[copy_size] = '\0';
    
    free(data);
    
    // Initialize pointer p to start of array
    p = start_color;
}