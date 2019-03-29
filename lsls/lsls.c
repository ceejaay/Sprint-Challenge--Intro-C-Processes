#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
/**
 * Main
 */


int main(int argc, char **argv)
{

  DIR *d;
  struct dirent *dir;
  struct stat buf;
  char *address;

  /* printf("Length of arg C %d\n", argc); */
  if(argv[1])
  {
    /* printf("Arg 0 => %s Arg 1 => %s\n", argv[0], argv[1]); */
    d = opendir(argv[1]);
    address = strcat(argv[1], "/");
    /* printf("here"); */
  } else {
    /* printf("Is is even geting here?\n"); */
    d = opendir(".");
    address = "./";
    /* printf("is this null? %d\n", d == NULL); */
  };


  if (d == NULL)
  {
    fprintf(stderr, "No such directory\n");
    exit(1);
  } else {
    while((dir = readdir(d)) != NULL)
    {
      /* printf("path %s\n", address); */
      char *new_address = strdup(address);
      /* printf("path to file %s\n", strcat(new_address, dir->d_name)); */
      stat(strcat(new_address, dir->d_name), &buf);
      printf("%10lld %s\n", buf.st_size, dir->d_name);
      /* free(address); */
    }
    closedir(d);
  }
  return 0;
}
