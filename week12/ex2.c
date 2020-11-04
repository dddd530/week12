#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n_files;
  n_files = argc - 2;

  if ((argc > 2) & (strcmp(argv[1], "-a") == 0) & (strcmp(argv[0], "tee") == 0)){
    //then everything is ok
  }
  //if no files
  else if((argc = 2) & (strcmp(argv[1], "-a") == 0) & (strcmp(argv[0], "tee") == 0)){
      char buf[100000];
    while(fgets(buf, 99999, stdin) != NULL){
      for(int i = 0; i < n_files; i++){
        printf("%s", buf);
      }
    }
  return 0;
  }
  //if command is not "tee -a ..."
  else(printf("It is not \"tee -a ...\" command :)"));


  FILE **files = malloc(n_files * sizeof(FILE));
  //open each file
  for(int i = 0; i < n_files; i++){
    files[i] = fopen(argv[2 + i], "a");
  }
  
  //writing data to each file and printig it on screen
  char buf[100000];
  while(fgets(buf, 99999, stdin) != NULL){
    for(int i = 0; i < n_files; i++){
      fprintf(files[i],"%s", buf)   ;
      }
    printf("%s", buf);
  }
  return 0;
}