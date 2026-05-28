#pragma once
double fracPart(double x);
void sortByFrac(double numbers[], int count, double (*criterion)(double));
void countCategories(double numbers[], int count, int& good, int& bad, int& neutral);
