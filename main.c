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
     if(argc<=3){
        printf("nothing to print");
        exit(EXIT_FAILURE);
     }


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
    //if first record mean first item line do another fgets(buffer, 1024, fp); then do same function since this acts as the header
    printf("%s",buffer);
    int j=0;
   
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
 //   printf("%d\n",j+1);   

    
    
    
    
    
    
    
    int min, max, mean=0;
    int r_count=0;
    int minr,maxr,meanr,recordr=0;
    //mean_value[32],max_value[32], min_value[32]
    //(strcmp(argv[i+1],"0")==0 ||atoi(argv[i+1])!=0 )
    char reader[10][64];
   
   int recn=0;
   char records[32][1024];
   
    if(fgets(buffer, 1024, fp)!=0){
    for (int i=0,j1=0, k=0; i<strlen(buffer); i++,k++){
      if(buffer[i]==44){
        i++;// i index in buffer
        j1++;// (j+1)th array
        k=0;//kth index of 
      }
      reader[j1][k]=buffer[i];
    }
    if(h_flag==1){



        if(record_flag==1 & (strcmp(record_field,"0")!=0 ||atoi(record_field)==0)){
             int inside=0;

             while(int i=0;i=<j+1;i++ ){
               if(strcmp(arr[i],record_field)==0){
                    inside=1;
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("no such field");
                     exit(EXIT_FAILURE);
                    }
                    recordr=i;
               }
            }
            if(inside==0){
                fprint("no such field invalid");
                exit(EXIT_FAILURE);
            }
            if(strcmp(record_value,reader[recordr])==0){
                records[recn]=buffer;
                recn++;
            }
        }
  
  
        if(max_flag==1 & (strcmp(max_value,"0")!=0 ||atoi(max_value)==0)){
             int inside=0;
             while(int i=0;i=<j+1;i++ ){
               if(strcmp(arr[i],max_value)==0){
                    maxr=i;
                    inside=1;
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("row not int");
                     exit(EXIT_FAILURE);
                    }
                    max=atoi(reader[i]);
               }
            }
            if(inside==0){
                fprint("max value invalid");
                exit(EXIT_FAILURE);
            }
        }
        else{exit(EXIT_FAILURE);}
        if(min_flag==1 & (strcmp(min_value,"0")!=0 ||atoi(min_value)==0)){
                int inside=0;

               while(int i=0;i=<j+1;i++ ){
                 if(strcmp(arr[i],min_value)==0){
                    minr=i;
                    inside=1;
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("row not int");
                     exit(EXIT_FAILURE);
                    }
                    min=atoi(reader[i]);

               }
            }
            if(inside==0){
                fprint("min value invalid");
                exit(EXIT_FAILURE);
            }

        }
        else{exit(EXIT_FAILURE);}
        if(mean_flag==1 & (strcmp(mean_value,"0")!=0 ||atoi(mean_value)==0)){
             int inside=0;

               while(int i=0;i=<j+1;i++ ){
                 meanr=i;
                 inside=1;
                  if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("row not int");
                     exit(EXIT_FAILURE);
                    }
                 mean=atoi(reader[i]);
            }
              if(inside==0){
                fprint("mean value invalid");
                exit(EXIT_FAILURE);
            }
        }
        else{exit(EXIT_FAILURE);}
       
    }
    else{

      
        if(record_flag==1 & (strcmp(record_field,"0")==0 ||atoi(record_field)!=0)){
             int inside=0;
             while(int i=0;i=<j+1;i++ ){
               if(strcmp(arr[i],record_field)==0){
                    inside=1;
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("no such field");
                     exit(EXIT_FAILURE);
                    }
                    recordr=i;
               }
            }
            if(inside==0){
                fprint("no such field invalid");
                exit(EXIT_FAILURE);
            }
            if(strcmp(record_value,reader[recordr])==0){
                records[recn]=buffer;
                recn++;
            }
        }
  

       if(max_flag==1 & strcmp(max_value,"0")==0 ||atoi(max_value)!=0){
               if(j+1>=atoi(max_value)){
                    maxr=atoi(max_value);
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("row not int");
                     exit(EXIT_FAILURE);
                    }
                    max=atoi(reader[i]);
               }  
            else {
                fprint("max value invalid");
                exit(EXIT_FAILURE);
            }
        }
        else{exit(EXIT_FAILURE);}
        if(min_flag==1 & strcmp(min_value,"0")==0 ||atoi(min_value)!=0){
               if(j+1>=atoi(min_value)){
                    minr=atoi(min_value);
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("row not int");
                     exit(EXIT_FAILURE);
                    }
                    min=atoi(reader[i]);
               }  
            else {
                fprint("max value invalid");
                exit(EXIT_FAILURE);
            }

        }
        else{exit(EXIT_FAILURE);}
        if(mean_flag==1 & strcmp(mean_value,"0")==0 ||atoi(mean_value)!=0){
             if(j+1>=atoi(mean_value)){
                    meanr=atoi(min_value);
                    if(strcmp(reader[i],"0")!=0 ||atoi(reader[i])==0){
                    fprint("row not int");
                     exit(EXIT_FAILURE);
                    }
                    mean=atoi(reader[i]);
               }  
            else {
                fprint("max value invalid");
                exit(EXIT_FAILURE);
            }

        }
        else{exit(EXIT_FAILURE);}


    }

    }
else{
 printf("no records available");
 if(f_flag==1){
        printf("%d\n",j+1); 
        exit(EXIT_SUCCESS);  
}
        exit(EXIT_FAILURE)
}








r_count=1;

//intialize, mean, min, max, meanr,minr,maxr(r=row)
//r_count=1  but current row 2 or 1 with h

char reader2[1024][10][64];// no time to malloc and free have to do with this way
int q=0;

while(fgets(buffer, 1024, fp)!=0){
     if(fgets(buffer, 1024, fp)!=0){
    for (int i=0,j1=0, k=0; i<strlen(buffer); i++,k++){
      if(buffer[i]==44){
        i++;// i index in buffer
        j1++;// (j+1)th array
        k=0;//kth index of 
      }
      reader2[q][j1][k]=buffer[i];
    }
    if(mean_flag==1 && (strcmp(reader2[q][meanr],"0")==0 ||atoi(reader2[q][meanr])!=0)){
    mean=mean+atoi(reader2[q][meanr]);
    }
    if(min_flag==1 && (strcmp(reader2[q][meanr],"0")==0 ||atoi(reader2[q][meanr])!=0)&(min>atoi(reader2[q][meanr]))){
    min=atoi(reader2[q][minr]);
    }
    if(max_flag==1 && (strcmp(reader2[q][meanr],"0")==0 ||atoi(reader2[q][meanr])!=0)&(max<atoi(reader2[q][meanr]))){
    max=atoi(reader2[q][maxr]);
    }

   if(record_flag==1 & (strcmp(record_field,"0")!=0 ||atoi(record_field)==0)){
            if(strcmp(record_value,reader2[q][recordr])==0){
                records[recn]=buffer;
                recn++;
            }
        }
  




    r_count++;
    q++;
}   
}
if(f_flag==1){
      printf("%d\n",j+1);   
}
if(r_flag==1){
    if(h_flag==1){
        printf("%d\n",r_count);
    }
    else{
        printf("%d\n",r_count+1);
    }
}
if(max_flag==1){
 printf("%d\n",max);
}
if(min_flag==1){
     printf("%d\n",mini);
}
if(mean_flag==1){
     printf("%d\n",mean/r_count);    
}
if(record_flag==1){
    printtf("%s",records);
}


    //read til end
//fgets(buffer, 1024, fp);//fgets(buffer, 1024, fp)==NULL // end of file use while(fgets(buffer, 1024, fp)=!NULL)
//printf("%s\n",buffer);}

/*
pseduo code 
only need to read the file until the end one time
everything beside -f require program to run until end -h too but -h has no effect on -f 

*/
 
    return 0;
}


