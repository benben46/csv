#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    char *filename = NULL;
    int max_flag, min_flag,mean_flag, f_flag, r_flag, h_flag, record_flag=0;
    char mean_value[32],max_value[32], min_value[32],record_field[32], record_value[32];

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


    //check if file exist
    filename=argv[argc-1];
   /* struct stat stats;
    stat(filename, &stats);
    printf("%d",stats.st_mode );
//test if file exist
    if (stats.st_mode!=0)
    {   
        printf("File %s exists", filename);
     }
     else{
        printf("File %s doesn't exist.", filename);
        exit(EXIT_FAILURE);

     }*/


     
    







//check if there is an .csv file if not early exit
   //printf("csv passed");


    for (int i = 2; i < (argc-1); i++) {
       // printf("current:%s\n",argv[i]);
        if (strcmp(argv[i], "-f") == 0) {
           f_flag = 1;
           printf("Flag -f\n");}
        else if (strcmp(argv[i], "-r") == 0) {
           r_flag = 1;
           printf("Flag -r\n");}
        else if (strcmp(argv[i], "-h") == 0) {
           h_flag = 1;
           printf("Flag -h\n");
        } else if (strcmp(argv[i], "-max") == 0 && (argc-1)>(i+1)) {
            //argc(i+2), i+1 max
            max_flag = 1;
            i=i+1;
            strcpy(max_value,argv[i]);
            printf("Flag -max %s\n",max_value);
           // printf("max_value%s\n",max_value);

        } else if((strcmp(argv[i], "-min") == 0) && ((argc-1)>(i+1)) ) {
           //argc(i+1), i+1 mini
            min_flag = 1;
            i=i+1;
            strcpy(min_value,argv[i]);
            printf("Flag -min %s\n",min_value);
         //   printf("min_value%s\n",min_value);

        }
        else if (strcmp(argv[i], "-mean") == 0 && (argc-1)>(i+1)) {
         //argc(i+2), i+1 mean
            mean_flag = 1;
            i=i+1;
            strcpy(mean_value,argv[i]);
            printf("Flag -mean %s \n",mean_value);

        }
         else if(strcmp(argv[i],"-records")== 0 && (argc-1)>(i+2)){
           //argc(i+2), i+1 record_field i+2 record_value
            record_flag = 1;
            strcpy(record_field,argv[i+1]);
            strcpy(record_value,argv[i+2]);
            printf("Flag -records %s %s\n",record_field,record_value);

            //printf("record_field %s\n",record_field);
            //printf("record_value %s\n",record_value);
            //not sure what to do with record_field and record value so keeping them as strings for now
            i=i+2;
        }
        else {
            printf("Unknown argument: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }
    char arr[10][64];
    FILE *fp;
    fp = fopen(filename,"r");
    if (fp == NULL)
    {
        printf("%s cannot be open",filename);
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    fgets(buffer, 1024, fp);
    //if first record mean first item line do another fgets(buffer, 1024, fp);
    printf("%s",buffer);
    int j=0;
    if(f_flag == 1){
        //sort into each item
    for (int i=0, k=0; i<strlen(buffer); i++,k++){
      if(buffer[i]==44){
        //printf("%s\n",arr[j]);//print each word seperated by comma
        i++;// i index in buffer
        j++;// (j+1)th array
        k=0;//kth index of 
      }
      arr[j][k]=buffer[i];
    }
  //  printf("%s\n",arr[j]);
    printf("%d\n",j+1);   

    }
fgets(buffer, 1024, fp);
printf("%s\n",buffer);


    return 0;
}


