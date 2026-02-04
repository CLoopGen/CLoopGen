#include <stdio.h>

#include <inttypes.h>

extern int dialect_number;
extern  char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int j;
    char *temp_p = p;
    for (i = 0; i < dialect_number; i++) {
        for (j = 0; temp_p[j] != '\0'; j++) {
            if (temp_p[j] == '|') {
                temp_p = &temp_p[j + 1];
                break;
            }
        }
    }
    p = temp_p;
}
