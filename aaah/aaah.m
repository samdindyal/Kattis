#include <stdio.h>
#include <string.h>

int main(void) {
  char *line1, *line2;
  line1 = line2 = NULL;
  size_t length;

  if (!getline(&line1, &length, stdin) || !getline(&line2, &length, stdin))
    return 1;

  printf("%s\n", strlen(line1) < strlen(line2) ? "no" : "go");
  return 0;
}
