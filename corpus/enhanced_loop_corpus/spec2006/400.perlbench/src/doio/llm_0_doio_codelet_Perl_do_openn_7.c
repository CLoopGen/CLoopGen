#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ((*name) == ' ' || (*name) == '\t' || (*name) == '\n' || (*name) == '\r' || (*name) == '\f'); name++) {
        for (int inner = 0; inner < 1 && ((*name) == ' ' || (*name) == '\t' || (*name) == '\n' || (*name) == '\r' || (*name) == '\f'); inner++) {
            // Simulated single-iteration inner loop to increase nesting depth
        }
    }
}
