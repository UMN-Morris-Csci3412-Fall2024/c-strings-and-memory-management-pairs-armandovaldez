#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *y = NULL;
  size_t size = 0;
  ssize_t nread;

 
  while ((nread = getline(&y, &size, stdin)) != -1) {
    
    if (nread > 0 && y[nread - 1] == '\n') {
      y[nread - 1] = '\0';
    }

    char *x = disemvowel(y);
    
    printf("%s\n", x);

    free(x);
  }

  free(y);

  return 0;
}
