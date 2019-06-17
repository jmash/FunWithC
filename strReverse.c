#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStrLen(char *);
void reverseString(char *, char *);

int main() {
  char * strPtr;
  char * revPtr;
  int strLen;
  strPtr = malloc(sizeof(char)*20);
  revPtr = malloc(sizeof(char)*20);

  strcpy(strPtr, "test string");
  strcpy(revPtr, strPtr);

  printf("%s\n", revPtr);
  reverseString(revPtr, strPtr);
  printf("%s\n", revPtr);

  free(strPtr);
  free(revPtr);

  return 0;
}

int getStrLen(char * str) {
  int strLen = 0;
  while(*str != '\0') {
    strLen++;
    str++;
  } 
  return strLen;
}

void reverseString(char * destStr, char * srcStr) {
  // check to make sure both strings are the same length
  int lenDest = getStrLen(destStr);
  int lenSrc = getStrLen(srcStr);
  int cd = lenSrc;
  if(lenDest != lenSrc) {
    fprintf(stderr, "Strings are not of the same length. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  srcStr += lenSrc-1;    // increment pointer to end of original string

  while(cd > 0) {
    *destStr = *srcStr; 
    destStr++;
    srcStr--;
    cd--;
  }
}
