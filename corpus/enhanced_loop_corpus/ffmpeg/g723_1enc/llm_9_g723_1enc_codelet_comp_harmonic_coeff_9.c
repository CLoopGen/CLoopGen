#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int doubled_energy;
for (i = 0; i < 7; i++) {
    doubled_energy = energy[2*i] * 2;
    if (doubled_energy < 0) doubled_energy = -doubled_energy;
    if (doubled_energy > max) max = doubled_energy;

    doubled_energy = energy[2*i + 1] * 2;
    if (doubled_energy < 0) doubled_energy = -doubled_energy;
    if (doubled_energy > max) max = doubled_energy;
}
}
