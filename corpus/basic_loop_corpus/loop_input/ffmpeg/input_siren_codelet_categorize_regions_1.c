#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int number_of_regions = 28;

int *power_categories;

int region;

int max_rate_categories[28] = {
    100, 105, 110, 115, 120, 125, 130, 135,
    140, 145, 150, 155, 160, 165, 170, 175,
    180, 185, 190, 195, 200, 205, 210, 215,
    220, 225, 230, 235
};

void init_vars() {
    power_categories = (int*)malloc(number_of_regions * sizeof(int));
    if (!power_categories) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}