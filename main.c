#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LENGTH 1024;

int max_func(int array[], int count) {
    int max = 0;
    int current_num = 0;

    for (int i = 0; i < count; i++) {
        current_num = array[i];
        if (max < current_num) {
            max = current_num;
        }
    }

    return max;
}

int min_func(int array[], int count) {
    int min = 999999;
    int current_num = 0;

    for (int i = 0; i < count; i++) {
        current_num = array[i];
        if (min > current_num) {
            min = current_num;
        }
    }

    return min;
}

int mean_func(int array[], int count) {
    int sum = 0;
    float mean = 0;

    for (int i = 0; i < count; i++) {
        sum += array[i];
        }
    mean = sum/count;

    return mean;
    }



int main(int argc, char *argv[]) {
    FILE *csv = NULL;
    char content[MAX_CHAR_LENGTH];
    //Specify your own .csv file name to use during command line
    csv = fopen(argv[1], "r");

    while (fgets(content, MAX_CHAR_LENGTH-1, csv) != NULL) {

    }

    fclose(csv);

}