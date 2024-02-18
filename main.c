#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    char *filename = NULL;
    int max_flag, min_flag,mean_flag, f_flag, r_flag, h_flag, record_flag=0;
    int mean_value,max_value, min_value;
    char record_field[32];
    char record_value[32];
//max, min

    if(strcmp(argv[1],"csv")<0){
        printf("missing argv[0], csv");
        exit(EXIT_FAILURE);
    }
    //check first argv

    char *csvarr= ".csv";
    for (int i=strlen(argv[argc-1])-4, j=0; i<strlen(argv[argc-1]); i++,j++){
        // printf("1%c\n",argv[argc-1][i]);
        //   printf("2%c\n",csvarr[j]);
        if(csvarr[j]!=(argv[argc-1][i])){
            printf("Missing csv file last input is not csv");
            exit(EXIT_FAILURE);
        }
    }
//check if there is an .csv file if not early exit
    filename=argv[argc-1];
    //printf("csv passed");


    for (int i = 2; i < (argc-1); i++) {
        printf("current:%s\n",argv[i]);
        if (strcmp(argv[i], "-f") == 0) {
            f_flag = 1;
            printf("Flag -f\n");}
        else if (strcmp(argv[i], "-r") == 0) {
            r_flag = 1;
            printf("Flag -r\n");}
        else if (strcmp(argv[i], "-h") == 0) {
            h_flag = 1;
            printf("Flag -h\n");
        } else if (strcmp(argv[i], "-max") == 0 && (argc-1)>(i+1) && (strcmp(argv[i+1],"0")==0 || atoi(argv[i+1])!=0 )) {
            //argc(i+2), i+1 max
            max_flag = 1;
            i=i+1;
            max_value=atoi(argv[i]);
            printf("Flag -max\n");
            printf("max_value%d\n",max_value);

        } else if((strcmp(argv[i], "-min") == 0) && ((argc-1)>(i+1)) &&  (strcmp(argv[i+1],"0")==0 ||atoi(argv[i+1])!=0 )) {
            //argc(i+1), i+1 mini
            min_flag = 1;
            i=i+1;
            min_value=atoi(argv[i]);
            printf("Flag -min\n");
            printf("min_value%d\n",min_value);

        }
        else if (strcmp(argv[i], "-mean") == 0 && (argc-1)>(i+1) && (strcmp(argv[i+1],"0")==0 ||atoi(argv[i+1])!=0 )) {
            //argc(i+2), i+1 mean
            mean_flag = 1;
            i=i+1;
            mean_value=atoi(argv[i]);
            printf("Flag -mean\n");
            printf("mean_value%d\n",mean_value);

        }
        else if(strcmp(argv[i],"-records")== 0 && (argc-1)>(i+2)){
            //argc(i+2), i+1 record_field i+2 record_value
            record_flag = 1;
            printf("Flag -records field value\n");
            strcpy(record_field,argv[i+1]);
            strcpy(record_value,argv[i+2]);
            printf("record_field%s\n",record_field);
            printf("record_value%s\n",record_value);
            //not sure what to do with record_field and record value so keeping them as strings for now
            i=i+2;
        }
        else {
            printf("Unknown argument: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }




    return 0;
}
/* #include <stdio.h>
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

} */
