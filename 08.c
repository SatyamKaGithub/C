#include <stdio.h>

int main() {
    int temperature_data[] = {25, 28, 27, 30, 31, 29, 26};
    int n = sizeof(temperature_data) / sizeof(temperature_data[0]);

    // A. Calculate the average temperature
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += temperature_data[i];
    }
    float average_temperature = (float)sum / n;
    printf("A. Average Temperature: %.2f\n", average_temperature);

    // B. Identify the hottest and coldest days
    int hottest_day = temperature_data[0];
    int coldest_day = temperature_data[0];
    for (int i = 1; i < n; i++) {
        if (temperature_data[i] > hottest_day) {
            hottest_day = temperature_data[i];
        }
        if (temperature_data[i] < coldest_day) {
            coldest_day = temperature_data[i];
        }
    }
    printf("B. Hottest Day: %d\n", hottest_day);
    printf("   Coldest Day: %d\n", coldest_day);

    // C. Calculate the temperature range
    int temperature_range = hottest_day - coldest_day;
    printf("C. Temperature Range: %d\n", temperature_range);

    return 0;
}