#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
/**
 * Main
 */

/* char *concat(char *s1, char *s2) */
/* { */
/*   char *result = malloc(strlen(s1) + strlen(s2) + 1); */
/*   strcpy(result, s1); */
/*   strcat(result, "/"); */
/*   /1* printf(" inside concat: %s\n", result); *1/ */
/*   strcat(result, s2); */
/*   return result; */
/* } */

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


  /* printf("concatted things => %s", strcat(argv[1], "/")); */
    /* printf(" This is just before checking for null on d. \n If no Arg 1 => %s Arg 1 => %s\n", argv[0], argv[1]); */
    /* printf("is this null before checking? %d\n", d == NULL); */
  if (d == NULL)
  {
    /* really we need an error here */
    fprintf(stderr, "No such directory\n");
    exit(1);
  } else {
    /* printf(" This is before while loop.  \n If no Arg 1 => %s Arg 1 => %s\n", argv[0], argv[1]); */
    /* printf("is this null? %d\n", d == NULL); */
    /* printf("Starting while loop"); */
    /* printf("Address: %s\n", address); */
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
