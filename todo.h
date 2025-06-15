#ifndef TODO_H
#define TODO_H

#define MAX_TASKS 100
#define MAX_LEN 100

typedef struct {
  char description[MAX_LEN];
} Task;


void add_task(const char *desc);
void view_task();
int complete_task(int index);


#endif // TODO_H

