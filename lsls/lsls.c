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

  /* printf("arg c: %d\n", argc); */
  /* char *thingy = concat("hello", "world"); */
  /* printf("concat result %s\n", thingy); */
  /* free(thingy); */


  DIR *d;
  /* char *address[128]; */
  struct dirent *dir;
  /* char thing; */
  struct stat buf;
  /* printf("args %s\n", argv[2]); */


  /* d = opendir("."); */
  /* int length = 0; */
  /* while(argv[length] != '\0') */
  /* { */
  /*   printf("args: %s\n", argv[length]); */
  /*   length++; */
  /* } */
  /* stat(".", &buf); */
  /* printf("size of file my prog => %lld\n",  buf.st_size); */

  if(argv[1])
  {
    d = opendir(argv[1]);
    /* char address[] = argv[1]; */
  } else

  {
    printf("here");
    d = opendir(".");
  }

  /* dir = readdir(d); */
  /* printf("directory name: %s", dir->d_name); */
  /* printf("argv: %s\n", argv[1]); */
  /* printf("D value => %d\n", d == '\0'); */

  /* d = opendir(argv[1]); */
  /* thing = readdir(d); */


    /* printf("%s\n", thing->d_name); */
  if (d == NULL)
  {
    /* really we need an error here */
    fprintf(stderr, "No such directory\n");
    exit(1);
  } else {
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

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}
