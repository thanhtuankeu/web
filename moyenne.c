#include "header.h"

// ./a.out -m '3*2.0+5*0.5' file.txt

int main(int argc, char **argv) {
  FILE *fp;
  fp = fopen("tuan.csm", "w+");
  char *resul = malloc(500);
  char const* const fileName = argv[argc-1];  //if argvs >1
  FILE* file = fopen(fileName, "r");  //if success
  char line[256];
  char * tokenX;
  char tab[6][250];
  const char s[2] = "+";
  const char s1[2] = "*";
  char * token;
  float eff[20];
  int a;
  float b;
  float sum = 0.0;
  float summer = 0.0;
  //extract value
  token  = strtok(argv[argc-2], s1);
  while(token !=NULL){
    a = atoi(token);
    token  =strtok(NULL,s) ;
    sscanf(token, "%f", &b);
    token = strtok(NULL,s1);
    eff[a] = b;
  }


  strcpy(resul,"");
  while (fgets(line, line_size, file)) {
    if(line[0]!='#' && strlen(line)>2){
      line[strlen(line)-1]='\0';
      tokenX = strtok(line," ; ");
      int i = 0;
      while( tokenX != NULL ) {
        strcpy(tab[i],tokenX);
        i = i +1;
        tokenX = strtok(NULL," ; ");
      }
      for(int i = 0;i<8;i++){
      if(eff[i] > 0.01){
          sum = sum + atof(tab[i])*eff[i] ;
          if(atof(tab[i])>0.01) summer = summer+eff[i];
        }
      }
      char xx[8];
      strcat(resul,tab[1]);
      strcat(resul," note is ");
      sprintf(xx, "%f",sum/summer);
      strcat(resul,xx);
      strcat(resul,"\n");
      sum = 0.0;
      summer = 0.0;
    }

  }
  int h = 0;
  for(int i = 1;i< argc-2;i++){
    if(strcmp(argv[i],"-h")==0) h=1;
    if(strcmp(argv[i],"-o")==0){
      i=i+1;
      printf(">--------------file resul save to %s\n", argv[i]);
      fp = fopen(argv[i], "w+");
      }
  }
  if(h) strcat(resul,">------------------help  option enable \n");
  printf("%s\n",resul );
  fputs(resul,fp);
  fclose(fp);
  free(resul);
  free(token);
  free(file);
  free(token);
  free(tokenX);
  return 0;
}
