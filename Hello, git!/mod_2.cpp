#include "mod_2.h"

double fracPart(double x) {
    if (x < 0) x = -x;
    return x - (int)x;
}

void sortByFrac(double numbers[], int count, double (*criterion)(double)) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (criterion(numbers[j]) < criterion(numbers[j + 1])) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void countCategories(double numbers[], int count, int& good, int& bad, int& neutral) {
    good = 0;
    bad = 0;
    neutral = 0;
    for (int i = 0; i < count; i++) {
        double frac = fracPart(numbers[i]);
        if (frac > 0.5) {
            good++;
        }
        else if (frac > 0.0 && frac <= 0.5) {
            bad++;
        }
        else {
            neutral++;
        }
    }
}