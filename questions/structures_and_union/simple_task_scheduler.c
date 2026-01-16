
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct task 
{
    int execution_count;
    int execution_interval;
    void* argument;
    int (*task_function)(void* argument);
};

struct task_scheduler 
{
    int scheduler_execution_count;
    int number_of_tasks;
    struct task* tasks;
};

void task_scheduler_init(struct task_scheduler* scheduler, struct task* task_list, int number_of_tasks)
{
    scheduler->scheduler_execution_count = 0;
    scheduler->tasks = task_list;
    scheduler->number_of_tasks = number_of_tasks;
}

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


int main(void)
{
    
}