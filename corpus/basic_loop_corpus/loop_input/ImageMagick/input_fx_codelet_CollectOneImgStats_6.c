#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct _ChannelStatistics {
    size_t depth;
    double area;
    double minima;
    double maxima;
    double sum;
    double sum_squared;
    double sum_cubed;
    double sum_fourth_power;
    double mean;
    double variance;
    double standard_deviation;
    double kurtosis;
    double skewness;
    double entropy;
    double median;
    long double sumLD;
    long double M1;
    long double M2;
    long double M3;
    long double M4;
} ChannelStatistics;

typedef float MagickFloatType;
typedef MagickFloatType Quantum;

int ch;
ChannelStatistics *cs;

void init_vars() {
    const int array_size = 65; // ch goes from 0 to 64 inclusive -> 65 elements
    cs = (ChannelStatistics*)calloc(array_size, sizeof(ChannelStatistics));
    
    if (!cs) {
        exit(1);
    }
    
    for (int i = 0; i < array_size; i++) {
        cs[i].mean = 1000.0 + i;
        cs[i].median = 1200.0 + i;
        cs[i].maxima = 2000.0 + i;
        cs[i].minima = 100.0 + i;
        cs[i].standard_deviation = 150.0 + i;
        
        cs[i].area = 5000.0 + i;
        cs[i].sum = 10000.0 + i;
        cs[i].sum_squared = 100000.0 + i;
        cs[i].sum_cubed = 1000000.0 + i;
        cs[i].sum_fourth_power = 10000000.0 + i;
        cs[i].variance = 22500.0 + i;
        cs[i].kurtosis = 3.0 + (i * 0.1);
        cs[i].skewness = 0.5 + (i * 0.05);
        cs[i].entropy = 1.0 + (i * 0.02);
        cs[i].sumLD = 100000.0L + i;
        cs[i].M1 = 1000.0L + i;
        cs[i].M2 = 1500.0L + i;
        cs[i].M3 = 2000.0L + i;
        cs[i].M4 = 2500.0L + i;
        cs[i].depth = i;
    }
}