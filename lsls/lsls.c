#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
/**
 * Main
 */

char *concat(char *s1, char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(result, s1);
  strcat(result, "/");
  /* printf(" inside concat: %s\n", result); */
  strcat(result, s2);
  return result;
}

int main(int argc, char **argv)
{

  DIR *d;
  struct dirent *dir;
  struct stat buf;
  /* printf("arg 1 %s\n", argv[1]); */
  /* d = opendir("."); */
  /* int length = 0; */
  /* while(argv[length] != '\0') */
  /* { */
  /*   printf("args: %s\n", argv[length]); */
  /*   length++; */
  /* } */
  /* stat(".", &buf); */
  /* printf("size of file my prog => %lld\n",  buf.st_size); */
  /* printf("checking for argv"); */
  if(argc >= 1)
  {
    printf("Arg 0 => %s Arg 1 => %s\n", argv[0], argv[1]);
    d = opendir(argv[1]);
    /* printf("here"); */
  } else

  {
    d = opendir(".");
    printf("Arg 0 => %s Arg 1 => %s\n", argv[0], argv[1]);
  }


  /* dir = readdir(d); */
  /* printf("directory name: %s\n", dir->d_name); */
  /* printf("argv: %s\n", argv[1]); */
  /* printf("D value => %d\n", d == '\0'); */

  /* d = opendir("."); */
  /* thing = readdir(d); */


    /* printf("%s\n", thing->d_name); */
  if (d == NULL)
  {
    /* really we need an error here */
    fprintf(stderr, "No such directory\n");
    exit(1);
  } else {
    printf("Starting while loop");
    while((dir = readdir(d)) != NULL)
    {
      /* if arg 1 == . or .. skip it */
      char *address = concat(argv[1], dir->d_name);
      /* printf("full path %s\n", address); */
      stat(address, &buf);
      printf("%10lld %s\n", buf.st_size, dir->d_name);
      free(address);
    }
    closedir(d);
  }
  return 0;
}
