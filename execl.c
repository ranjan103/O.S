 #include <sys/types.h>
  #include <unistd.h>
  #include <stdio.h>

int main()
{
char *ab[] = {"./dat",NULL}; 
execl("./dat",ab); 
}
