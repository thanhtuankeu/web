#include "header.h"

void tri_insertion(char  tableau[5][250],int spe, int longueur) // small
{
  char info[6][50];
  char knfo[6][50];
  /*
  sscanf( tableau[0], "%s ; %s ; %s ; %s ; %s ; %s",info[0],info[1],info[2],info[3],info[4],info[5]);
  printf("%s\n", info[3]);
  */
  char * memory = malloc(250);
  int i, compt, marqueur;

  for(i = 1; i < longueur;i++){
    strcpy(memory, tableau[i]);
    compt = i-1;
    do
    {
      marqueur = 0;
      sscanf( tableau[compt], "%s ; %s ; %s ; %s ; %s ; %s",info[0],info[1],info[2],info[3],info[4],info[5]);
      sscanf( memory, "%s ; %s ; %s ; %s ; %s ; %s",knfo[0],knfo[1],knfo[2],knfo[3],knfo[4],knfo[5]);

      if(strcmp(info[spe],knfo[spe])>0){
        strcpy(tableau[compt+1],tableau[compt]);
        compt--;
        marqueur=1;
      }
      if(compt<0) marqueur = 0;
    }
    while(marqueur);

    strcpy(tableau[compt+1],memory);
  }
}

int main(int argv, char ** argvs){
  FILE *fp;
  fp = fopen("tuan.csm", "w+");

  char *resul = malloc(5000);
  char const* const fileName = argvs[2];
  FILE* file = fopen(fileName, "r");
  int r = atoi(argvs[1]);
  if(r>5) printf("not a valid number");
  else{
    char tab[50][250];
    int io = 0;
    if(file!=NULL){
      char * line  = malloc(500);

      while (fgets(line, line_size, file)) {
        if(line[0]!='#' && strlen(line)>2){
          strcat(tab[io],line);
          io+=1;
        }
        else strcat(resul,line);
      }
      fclose(file);
    }
    tri_insertion(tab,r,io);
    for(int i = 0;i<io;i++){
      strcat(resul,tab[i]);
    }
    printf("%s",resul);
    fputs(resul, fp);
    free(resul);
  }
  fclose(file);

}
//  ./a.out 0 file.txt
