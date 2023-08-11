#include <stdio.h>

// Function to calculate the average score
float calculateAverage(int scores[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += scores[i];
    }
    return (float)total / n;
}

// Function to calculate the highest score
int calculateHighest(int scores[], int n) {
    int highest = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

// Function to count passed and failed students
void countPassedFailed(int scores[], int n, int passingThreshold, int *passed, int *failed) {
    *passed = 0;
    *failed = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= passingThreshold) {
            (*passed)++;
        } else {
            (*failed)++;
        }
    }
}

// Function to determine grade distribution
void determineGradeDistribution(int scores[], int n, int gradeDistribution[]) {
    for (int i = 0; i < n; i++) {
        if (scores[i] >= 90) {
            gradeDistribution[0]++;
        } else if (scores[i] >= 80) {
            gradeDistribution[1]++;
        } else if (scores[i] >= 70) {
            gradeDistribution[2]++;
        } else if (scores[i] >= 60) {
            gradeDistribution[3]++;
        } else {
            gradeDistribution[4]++;
        }
    }
}

int main() {
    int test_scores[] = {85, 78, 92, 65, 89, 76, 94, 81, 87, 90, 72, 88, 95, 79, 83, 91, 70, 84, 86, 93};
    int n = sizeof(test_scores) / sizeof(test_scores[0]);

    // A. Calculate average and highest score
    float average_score = calculateAverage(test_scores, n);
    int highest_score = calculateHighest(test_scores, n);
    printf("A. Average Score: %.2f\n", average_score);
    printf("   Highest Score: %d\n", highest_score);

    // B. Count passed and failed students
    int passing_threshold = 60;
    int passed, failed;
    countPassedFailed(test_scores, n, passing_threshold, &passed, &failed);
    printf("B. Students Passed: %d\n", passed);
    printf("   Students Failed: %d\n", failed);

    // C. Determine grade distribution
    int gradeDistribution[5] = {0}; // O, E, A, B, F
    determineGradeDistribution(test_scores, n, gradeDistribution);
    printf("C. Grade Distribution:\n");
    printf("   O: %d\n", gradeDistribution[0]);
    printf("   E: %d\n", gradeDistribution[1]);
    printf("   A: %d\n", gradeDistribution[2]);
    printf("   B: %d\n", gradeDistribution[3]);
    printf("   F: %d\n", gradeDistribution[4]);

    return 0;
}