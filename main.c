#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = NULL;
    int max_flag, min_flag,mean_flag, f_flag, r_flag, h_flag, record_flag=0;
    int mean_value,max_value, min_value;
    char record_field, record_value;
//max, min
    if(argv[0]!="csv"){
         exit(EXIT_FAILURE);
        printf("missing argv[0], csv");
    }
    //check first argv

    if((&argv[][len-4]==".csv"))
    {
         //check if there is an .csv file if not early exit
        filename=argv[argc-1];
    }
    else{
            printf("Missing csv file last input is not csv");
            exit(EXIT_FAILURE)
            
        }


    for (int i = 1; i < (argc-1); i++) {
        if (strcmp(argv[i], "-f") == 0) {
           f_flag = 1;
           printf("Flag -f"\n);}
        if (strcmp(argv[i], "-r") == 0) {
           r_flag = 1;
           printf("Flag -r\n");}
        else if (strcmp(argv[i], "-h") == 0) {
           h_flag = 1;
           printf("Flag -h\n");
        } else if (strcmp(argv[i], "-max") == 0 && (argc-1)>(i+1) && isdigit(argv[i+1])) { 
            //argc(i+2), i+1 max 
            max_flag = 1;
            i=i+1;
            max_value=atoi(argv[i]);
            printf("Flag -max\n");
            printf("max_value%d\n",max_value);

        } else if (strcmp(argv[i], "-min") == 0 && (argc-1)>(i+1) && isdigit(argv[i+1])) {
           //argc(i+1), i+1 mini
            min_flag = 1;
            i=i+1;
            min_value=atoi(argv[i]);
            printf("Flag -min\n");
            printf("min_value%d\n",min_value);

        } 
        else if (strcmp(argv[i], "-mean") == 0 && (argc-1)>(i+1) && isdigit(argv[i+1])) {
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
            record_field=argv[i+1];
            record_value=argv[i+2];
            printf("record_field%d\n",record_field);
            printf("record_value%d\n",record_value);
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
