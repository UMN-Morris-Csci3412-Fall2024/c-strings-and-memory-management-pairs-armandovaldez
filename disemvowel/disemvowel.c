#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

#include "disemvowel.h"

int is_vowel(char c) {
  char lower = tolower(c);
  return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

char *disemvowel(char *str) {
  int len = strlen(str);
  int c = 0;

  for (int i = 0; i < len; i++) {
    if (!is_vowel(str[i])) {
      c++;
    }
  }

  char *result = (char*) calloc(c + 1, sizeof(char));

  int j = 0;
  for (int i = 0; i < len; i++) {
    if (!is_vowel(str[i])) {
      result[j++] = str[i];
    }
  }

  result[c] = '\0';  

  return result;
}
