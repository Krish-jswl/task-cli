#include <stdio.h>
#include <string.h>
#include "todo.h"

Task todoList[MAX_TASKS];
int taskCount = 0;

void add_task(const char *desc){
 
  if(taskCount >= MAX_TASKS){
    printf("Too many tasks!\n");
    return ;
  }

  strncpy(todoList[taskCount].description, desc, MAX_LEN - 1);
  todoList[taskCount].description[MAX_LEN - 1] = '\0';

  FILE *file = fopen("tasks.txt","a");
  if ( file != NULL ){
    fprintf(file, "%s\n", todoList[taskCount].description);
    fclose(file);
  }

  taskCount++;
  printf("Task added!\n");
}


void view_task(){

FILE *file = fopen("tasks.txt", "r");
  char line[MAX_LEN];
  int index = 1;
  if (file != NULL ){
    while (fgets(line,sizeof(line),file)) {
      printf("%d. %s", index++, line);
    }
    fclose(file);
  } else {
    printf("No task yet. \n");
  }
}

int complete_task(int index){
  
  FILE *file = fopen("tasks.txt","r");
  if (!file){
    perror("Error in opening file");
    return -1;
  }

  FILE *temp = fopen("temp_task.txt", "w");
  if (!temp){
    perror("Error opening temp file");
    fclose(file);
    return -1;
  }

  char buffer[1024];
  int current_line = 1;

  while (fgets(buffer, sizeof(buffer), file)){
    if (current_line != index){
      fputs(buffer, temp);
    }
    current_line++;
  }

  fclose(file);
  fclose(temp);

  remove("tasks.txt");
  rename("temp_task.txt", "tasks.txt");

  printf("Task completed!\n");

  return 0;

}
