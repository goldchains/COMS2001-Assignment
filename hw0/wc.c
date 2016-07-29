#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void wc ( FILE *infile, char *inname);

int main (int argc, char *argv[]) {
   int wordcount =  0;
   int i;
   for(i = 1;i < argc; i++){
     FILE *fp;
     fp = fopen(argv[i],"r");
     wc(fp,argv[i]);
    fclose(fp);
   }

}

void wc( FILE *infile, char *inname) {
     char line[256];
     int i;
     int wordcount = 0;
    if(read_line(infile, line, sizeof line)){
    for(i=0;line[i] != '\0';i++){
      if(line[i]==' ' && line[i+1] != ' ')
         wordcount++;
    }
      printf("number of words: %d \n", wordcount);}
    else
      printf("read error\n");

  /*   do{
        ch = getc(infile);
        printf("%c",ch);
     }while(ch != EOF);*/
   }
int read_line(FILE *in, char *buffer, size_t max)
{
  return fgets(buffer, max, in) == buffer;
}
