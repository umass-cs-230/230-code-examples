// getenv, setenv, and unsetenv in stdlib.h:
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[], char *envp[]) {
  // We can loop over envp array:
  int i = 0;
  while (envp[i] != NULL) {
    printf("%s\n", envp[i]);
    i++;
  }

  // We can get a specific environment variable:
  char *user = getenv("USER");
  if (user != NULL) {
    printf("getenv: %s\n", user);
  }

  // We can set an environment variable:
  int ret = setenv("USER", "fred", 1);
  printf("setenv: %d\n", ret);
  user = getenv("USER");
  if (user != NULL) {
    printf("setenv: %s\n", user);
  }

  // We can unset an environment variable:
  unsetenv("USER");
  user = getenv("USER");
  if (user == NULL) {
    printf("unsetenv: no USER variable\n");
  }
  
  return 0;
}

