#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int elems = 131072; // 128K elements for ~0.01 sec runtime estimate

uint8_t lens[644] = {0};

uint16_t codes[644] = {0};

int prefixes[18] = {0};

int i = 0;

void init_vars() {
    for (int j = 0; j < 644; j++) {
        lens[j] = rand() % 18;
    }
    for (int j = 0; j < 18; j++) {
        prefixes[j] = j * 1000;
    }
    for (int j = 0; j < 644; j++) {
        codes[j] = 0;
    }
    elems = 644; // Ensure loop stays within bounds of lens and codes
}