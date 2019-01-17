#include "header.h"

int main(int argv, char ** argvs){

  FILE *fp;
  fp = fopen("tuan.csm", "w+");


  char *resul = malloc(500);
  char line[500];
    int i=1;

    strcpy(resul,"");
    while(i<argv){
      char const* const fileName = argvs[i];  //if argvs >1

      FILE* file = fopen(fileName, "r");  //if success

      while (fgets(line,line_size, file)) {
        strcat(resul,line);
      }

      fclose(file);
      i = i+1;
    }
    printf("%s", resul);
    fputs(resul, fp);
    fclose(fp);
    free (resul);
  return 0;


}


//  ./a.out file2.txt file.txt
