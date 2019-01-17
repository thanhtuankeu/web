#include "header.h"

int main(int argv, char ** argvs){
  FILE *fp;
  fp = fopen("tuan.csm", "w+");
  char *resul = malloc(500);
  char line[256];
  char const* const fileName = argvs[argv-1];  //if argvs >1
  FILE* file = fopen(fileName, "r");  //if success

  char * token;

  char tab[6][250];

  while (fgets(line, line_size, file)) {
    if(line[0]!='#' && strlen(line)>2){
      line[strlen(line)-1]='\0';
      /*
      token = strtok(line," ; ");

      while( token != NULL ) {
      strcpy(tab[coc],token) ;
      coc = coc+1;
      token = strtok(NULL," ; ");
    }
    */
    token = strtok(line," ; ");
    int i = 0;
    while( token != NULL ) {
      printf("*%s*",token);
      strcpy(tab[i],token);
      i = i +1;
      token = strtok(NULL," ; ");
    }
    for(int ii = 1; ii <argv-1;ii++){
      strcat(resul,tab[atoi(argvs[ii])]);
      strcat(resul," ; ");
    }
    resul[strlen(resul)-2]='\0';
    strcat(resul,"\n");

  }
  }

  printf("%s",resul);
  fclose(file);
  fputs(resul, fp);
  fclose(fp);
  free(resul);
  free(token);
}

//  ./a.out 0 1 2 3 4 4 file.txt
