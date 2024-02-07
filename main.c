#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = NULL;
    int max_flag = 0, min_flag = 0, field_flag;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
           field_flag = 1;
           printf("Flag -f\n");
        } else if (strcmp(argv[i], "-max") == 0) {
            max_flag = 1;
            printf("Flag -max\n");
        } else if (strcmp(argv[i], "-min") == 0) {
            min_flag = 1;
            printf("Flag -min\n");
        } else {
            printf("Unknown argument: %s\n", argv[i]);
        }
    }


    return 0;
}
