
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//
// Explain the purpose of the elements in the structure.
//
// Your explanation (mandatory):
//
//
//

struct task 
{
    int execution_count;
    int execution_interval;
    void* argument;
    int (*task_function)(void* argument);
};

//
// Explain the purpose of the elements in the structure.
//
// Your explanation (mandatory):
//
//
//

struct task_scheduler 
{
    int scheduler_execution_count;
    int number_of_tasks;
    struct task* tasks;
};

//
// Add comments to the function task_scheduler_init.
// Explain the working of thie function and what it does
//
// Your answer & explanation (mandatory):
//
//
//
//


void task_scheduler_init(struct task_scheduler* scheduler, struct task* task_list, int number_of_tasks)
{
    scheduler->scheduler_execution_count = 0;
    scheduler->tasks = task_list;
    scheduler->number_of_tasks = number_of_tasks;
}

//
// Add comments to the function task_execute.
// Explain the working of thie function and what it does
//
// Your answer & explanation (mandatory):
//
//
//
//

int task_scheduler_execute(struct task_scheduler* scheduler)
{
    int index = 0;
    int ret;

    struct task* task;

    for( index = 0 ; index < scheduler->number_of_tasks ; index++ )
    {
        task = &scheduler->tasks[index];

        task->execution_count++;

        if( task->execution_count >= task->execution_interval )
        {
            task->execution_count = 0;
            ret = task->task_function( task->argument );

            if( ret < 0 )
            {
                return ret;
            }
        }
    }

    return 0;
}


static int task_counter_1;
static int task_counter_2;
static int task_counter_3;

int task_function_1(void* args)
{
    int* count = (int*)args;

    (*count)++;
    printf("task_function_1: execution_count: %d\n", *count);
}

int task_function_2(void* args)
{
    int* count = (int*)args;

    (*count)++;
    printf("task_function_2: execution_count: %d\n", *count);
}

int task_function_3(void* args)
{
    int* count = (int*)args;

    (*count)++;
    printf("task_function_3: execution_count: %d\n", *count);
}

static struct task task1 = {
    .argument = &task_counter_1,
    .execution_count = 0,
    .execution_interval = 1,
    .task_function = task_function_1,
};

static struct task task2 = {
    .argument = &task_counter_2,
    .execution_count = 0,
    .execution_interval = 2,
    .task_function = task_function_2,
};

static struct task task3 = {
    .argument = &task_counter_3,
    .execution_count = 0,
    .execution_interval = 3,
    .task_function = task_function_3,
};

static struct task tasks[3];
static struct task_scheduler scheduler;

int main(void)
{
    task_counter_1 = 0;
    task_counter_2 = 0;
    task_counter_3 = 0;

    tasks[0] = task1;
    tasks[1] = task2;
    tasks[2] = task3;

    task_scheduler_init(&scheduler, tasks, sizeof(tasks)/sizeof(tasks[0]));

    int index = 0;

    //
    //  Explain the reason why the generated output is
    //  generated.
    //

    for( index = 0 ; index < 12 ; index++ )
    {
        (void)task_scheduler_execute(&scheduler);
    }

    return 0;
}