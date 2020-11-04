#include <stdio.h>

int main(void) {
  FILE *file = fopen("/dev/random", "r");
  char buf[21];
  int i = 0;
  while(i < 20){
    int c = fgetc(file);
    if(c >= 32 & c <= 126){
      buf[i] = c;
      i++;
    }
  }
  
  for(int i = 0; i < 20; i++){
    printf("%c", buf[i]);
  }
  fclose(file);
}