#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  if (argc < 5) {
    printf("Missing arguments\n");
    return 1;
  }

  srand(time(NULL));

  char *name_arr[4] = {argv[1], argv[2], argv[3], argv[4]};
  for (int i = 0; i < 4; i++) {
    int new_pos = i + rand() / (RAND_MAX / (4 - i) + 1);
    char *temp = name_arr[new_pos];
    name_arr[new_pos] = name_arr[i];
    name_arr[i] = temp;
  }

  for (int i = 0; i < 4; i++) {
    switch (i) {
    case 0 ... 1:
      printf("T1: %s\n", name_arr[i]);
      break;
    case 2 ... 3:
      printf("T2: %s\n", name_arr[i]);
      break;
    }
  }

  return 0;
}
