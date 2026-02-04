#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    UndefinedStatistic,
    GradientStatistic,
    MaximumStatistic,
    MeanStatistic,
    MedianStatistic,
    MinimumStatistic,
    ModeStatistic,
    NonpeakStatistic,
    RootMeanSquareStatistic,
    StandardDeviationStatistic,
    ContrastStatistic
} StatisticType;

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

extern  StatisticType type;
extern ChannelStatistics *channel_statistics;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const ssize_t indices[] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 
                            7, 15, 23, 31, 39, 47, 55, 63, 
                            1, 9, 17, 25, 33, 41, 49, 57, 
                            6, 14, 22, 30, 38, 46, 54, 62, 
                            2, 10, 18, 26, 34, 42, 50, 58, 
                            5, 13, 21, 29, 37, 45, 53, 61, 
                            3, 11, 19, 27, 35, 43, 51, 59, 
                            4, 12, 20, 28, 36, 44, 52, 60};
for (ssize_t j = 0; j < 65; j++) {
    ssize_t idx = indices[j];
    switch (type) {
      case MaximumStatistic:
      default:
        {
            channel_statistics[idx].maxima = (-1.7976931348623157E+308);
            break;
        }
      case MinimumStatistic:
        {
            channel_statistics[idx].minima = 1.7976931348623157E+308;
            break;
        }
    }
}
}
