#include "header.h"

// ./commande -o [fichier]
// ./commande -s c
// ./commande -h

int fichier_sortie();
int separateur();
void help();

int main(int argc, char *argv[]) {
    
    int opt;
    
    while((opt = getopt(argc, argv, "o:s:h")) != EOF){
        
        switch(opt) {
            case 'o':
                fichier_sortie(argc,argv);
                break;
                
            case 's':
                separateur(argc, argv);
                break;
                
            case 'h':
                help();
                break;
                
            default:
                break;
        }
    }
    
    return 0;
}

// Creer un fichier : -o [le nom de fichier]
int fichier_sortie(int argc, char **argv){
    if (argc == 3) {
        int len=strlen(argv[2]);
        char *fname=(char*)malloc(len);
        char *fname1;
        char answer;
        FILE *fp;
        
        strcpy(fname, argv[2]);
        
        // Add '.csm' extension
        for(int i=len+1; fname[i] != '.'; i--){
            fname1=strcat(fname,".csm");
        }
        
        int j=0;
        while (fname[j] != '.') {
            j++;
        }
        fname[j]='\0';
        fname1=strcat(fname,".csm");
        
        
        // Check if there is the same file or not
        if((fp = fopen(fname1, "r")) == NULL) {
            fp=fopen(fname1, "w");
            if (fp == NULL) {
                fprintf(stderr,"ERROR!! \n");
                exit(0);
            }
            
        }else{
            printf("fichier : %s deja existe.\nEst-ce que vous voulez ecraser ce fichier? [y/n] \n",fname);
            scanf("%s",&answer);
            if (answer == 'y') {
                printf("Le fichier %s est ecrase.\n",fname);
                unlink(fname);
            }else{
                printf("Le fichier %s est garde.\n",fname);
            }
        }
        fclose(fp);
        free(fname);
        free(fname1);
    }
    
    return 0;
}


// separateur : -s c [le caractere]
int separateur(int argc, char **argv){
    
    FILE *fp=fopen("data.csm", "w");
    if (fp == NULL) {
        fprintf(stderr,"ERROR!! \n");
        exit(0);
    }
    
    if (argc == 3) {
        fputs(argv[2], fp);
    }
    
    fclose(fp);
    return 0;
    
}

//Explain about commandes
void help(){
    /*
     usage: man [-adfhktwW] [section] [-M path] [-P pager] [-S list]
     [-m system] [-p string] name ...
     a : find all matching entries
     */
    
    printf("usage : nom_commande [option] [fichier] \n");
    printf(" -o : -o commande cree un fichier. <forme : -o [fichier]> \n");
    printf(" -s : -s commande utilise comme separateur pour le fichier sortie. <forme : -s c(le caractere)> \n");
    printf(" -h : -h commande affiche l'aide de la commande. <forme : -h> \n");
    
}
