#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10       // Maximum number of tasks allowed
#define MAX_TASK_LENGTH 50 // Maximum length of a task description

// Structure to represent a task
typedef struct
{
    char task[MAX_TASK_LENGTH]; // Task description
    int completed;              // 0 if not completed, 1 if completed
} Task;

Task tasks[MAX_TASKS]; // Array to store tasks
int task_count = 0;    // Number of tasks currently in the list

// Function to add a new task to the list
void add_task()
{
    // Check if the task list is full
    if (task_count < MAX_TASKS)
    {
        printf("Enter task: ");
        fgets(tasks[task_count].task, MAX_TASK_LENGTH, stdin);             // Read task description from the user
        tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = 0; // remove newline character
        tasks[task_count].completed = 0;                                   // Set the task as not completed
        task_count++;                                                      // Increment the task count
        printf("Task added!\n");
    }
    else
    {
        printf("Task list is full!\n");
    }
}

// Function to view all tasks in the list
void view_tasks()
{
    // Check if there are any tasks to display
    if (task_count == 0)
    {
        printf("No tasks to display!\n");
    }
    else
    {
        printf("Tasks:\n");
        // Iterate through the task list and print each task
        for (int i = 0; i < task_count; i++)
        {
            printf("%d. %s (%s)\n", i + 1, tasks[i].task, tasks[i].completed ? "Completed" : "Not Completed");
            // print its index, description, and completion status
        }
    }
}

// Function to mark a task as completed
void complete_task()
{
    // Check if there are any tasks to complete
    if (task_count == 0)
    {
        printf("No tasks to complete!\n");
    }
    else
    {
        printf("Enter task number to complete: ");
        int task_number;
        scanf("%d", &task_number);
        getchar(); // consume newline character
        // Check if the task number is valid
        if (task_number > 0 && task_number <= task_count)
        {
            tasks[task_number - 1].completed = 1; // Mark the task as completed
            printf("Task completed!\n");
        }
        else
        {
            printf("Invalid task number!\n");
        }
    }
}

// Function to delete a task from the list
void delete_task()
{
    // Check if there are any tasks to delete
    if (task_count == 0)
    {
        printf("No tasks to delete!\n");
    }
    else
    {
        printf("Enter task number to delete: ");
        int task_number;
        scanf("%d", &task_number);
        getchar(); // consume newline character
        // Check if the task number is valid
        if (task_number > 0 && task_number <= task_count)
        {
            // Shift the tasks after the deleted task to fill the gap
            for (int i = task_number - 1; i < task_count - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            task_count--; // Decrement the task count
            printf("Task deleted!\n");
        }
        else
        {
            printf("Invalid task number!\n");
        }
    }
}

// Main function
int main()
{
    // Main loop to display the menu and handle user input
    while (1)
    {
        printf("1. Add task\n");
        printf("2. View tasks\n");
        printf("3. Complete task\n");
        printf("4. Delete task\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline character
        // Switch statement to handle user choice
        switch (choice)
        {
        case 1:
            add_task();
            break;
        case 2:
            view_tasks();
            break;
        case 3:
            complete_task();
            break;
        case 4:
            delete_task();
            break;
        case 5:
            return 0; // Exit the program
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
