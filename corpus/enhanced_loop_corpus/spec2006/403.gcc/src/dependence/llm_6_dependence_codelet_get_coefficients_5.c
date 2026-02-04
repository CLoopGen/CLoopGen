#include <stdio.h>

#include <inttypes.h>

typedef struct subscript {
    int position;
    int coefficient;
    int offset;
    const char *variable;
    struct subscript *next;
} subscript;

extern subscript coefficients[13];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce WAW and WAR dependencies by reordering writes and introducing artificial dependencies
    for (i = 0; i < 13; i++) {
        coefficients[i].position = 0;
        coefficients[i].coefficient = (-2147483647 - 1);
        coefficients[i].offset = (-2147483647 - 1);
        coefficients[i].variable = 0;
        coefficients[i].next = 0;

        // Create WAR dependency (Write-After-Read) hazard artificially by reading from next iteration's data
        if (i > 0) {
            coefficients[i-1].position += coefficients[i].coefficient + 1; // Use current to modify previous
        }
    }

    // Introduce a second pass with loop-carried dependence (WAW: Write-After-Write)
    for (i = 12; i >= 0; i--) {
        coefficients[i].coefficient = coefficients[i].offset + 100; // Depends on prior write in first loop
    }
}
