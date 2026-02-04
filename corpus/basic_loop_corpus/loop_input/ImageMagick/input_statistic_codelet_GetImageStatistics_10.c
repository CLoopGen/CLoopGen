#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
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

ChannelStatistics *channel_statistics;
ssize_t i;

void init_vars() {
    const size_t num_elements = 65;
    channel_statistics = (ChannelStatistics*)calloc(num_elements, sizeof(ChannelStatistics));
    if (!channel_statistics) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < num_elements; idx++) {
        ChannelStatistics *cs = &channel_statistics[idx];
        cs->area = 0.;
        cs->depth = 1;
        cs->maxima = -1.7976931348623157E+308;
        cs->minima = 1.7976931348623157E+308;
        cs->sum = 0.;
        cs->sum_squared = 0.;
        cs->sum_cubed = 0.;
        cs->sum_fourth_power = 0.;
        cs->mean = 0.;
        cs->variance = 0.;
        cs->standard_deviation = 0.;
        cs->kurtosis = 0.;
        cs->skewness = 0.;
        cs->entropy = 0.;
        cs->median = 0.;
        cs->sumLD = 0.;
        cs->M1 = 0.;
        cs->M2 = 0.;
        cs->M3 = 0.;
        cs->M4 = 0.;
    }
}