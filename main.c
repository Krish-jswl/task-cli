#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "todo.h"

int main(int argc, char *argv[])
{
 
  if (argc < 2){
    printf("Usage:\n");
    printf(" ./task -a \"task description\"\n");
    printf(" ./task -v\n");
    printf(" ./task -c <index>\n");
    return 1;
  }

  if (strcmp(argv[1], "-a") == 0 && argc >= 3){
    add_task(argv[2]);
  }
  else if (strcmp(argv[1], "-v") == 0) {
    view_task();
  }
  else if (strcmp(argv[1], "-c") == 0 && argc >= 3) {
    int index = atoi(argv[2]);
    if (index <= 0){
      printf("Invalid index. Use a positive number.\n");
    }
    complete_task(index);
  }
  else {
    printf("Invalid command or missing aargumnets!\n");
  }
  return 0;
}

