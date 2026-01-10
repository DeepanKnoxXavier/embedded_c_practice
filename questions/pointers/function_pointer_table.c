
#include <stdint.h>
#include <stdio.h>

#define STATE_STATUS_ENTRY         0
#define STATE_STATUS_DURING        1
#define STATE_STATUS_EXIT          2

#define EVENT_START_SIGNAL         0
#define EVENT_DURING_SIGNAL        1
#define EVENT_DONE_SIGNAL          2

struct state
{
    int state;
    int state_status;
    void* args;
    int (*entry)(struct state*, int);
    int (*during)(struct state*, int);
    int (*exit)(struct state*, int);
};

static int state_1_entry(struct state* state, int event)
{
    if( event == EVENT_START_SIGNAL )
    {
        state->state_status = STATE_STATUS_DURING;
    }

    return( state->state );
}

static int state_1_during(struct state* state, int event)
{
    uint32_t* ptr;

    ptr = state->args;

    if( event == EVENT_DURING_SIGNAL )
    {
        *ptr += 1;

        if( *ptr == 10 )
        {
            state->state_status = STATE_STATUS_EXIT;
        }
    }
    else if( event == EVENT_DONE_SIGNAL )
    {
        state->state_status = STATE_STATUS_EXIT;
    }

    return state->state;
}


static int state_1_exit(struct state* state, int event)
{
    return state->state + 1;
}


static int state_2_entry(struct state* state, int event)
{
    if( event == EVENT_START_SIGNAL )
    {
        *((uint32_t*)state->args) = 100;
        state->state_status = STATE_STATUS_DURING;
    }

    return( state->state );
}

static int state_2_during(struct state* state, int event)
{
    uint32_t* ptr;

    ptr = state->args;

    if( event == EVENT_DURING_SIGNAL )
    {
        *ptr -= 1;

        if( *ptr == 0 )
        {
            state->state_status = STATE_STATUS_EXIT;
        }
    }
    else if( event == EVENT_DONE_SIGNAL )
    {
        state->state_status = STATE_STATUS_EXIT;
    }

    return state->state;
}


static int state_2_exit(struct state* state, int event)
{
    return 0;
}

int execute_state_machine(struct state* state, int event)
{
    int ret = state->state;

    switch( state->state_status )
    {
        case STATE_STATUS_ENTRY:
            ret = state->entry( state, event );
        break;

        case STATE_STATUS_DURING:
            ret = state->during( state, event );
        break;

        case STATE_STATUS_EXIT:
            ret = state->exit( state, event );
        break;
    }

    return ret;
}

static int state_variable_1;
static int state_variable_2;

struct state s1 = {
    .state = 0,
    .state_status = STATE_STATUS_ENTRY,
    .args = (void*)&state_variable_1,
    .entry = state_1_entry,
    .during = state_1_during,
    .exit = state_1_exit,
};


struct state s2 = {
    .state = 1,
    .state_status = STATE_STATUS_ENTRY,
    .args = (void*)&state_variable_2,
    .entry = state_2_entry,
    .during = state_2_during,
    .exit = state_2_exit,
};

struct state* states[] = { &s1, &s2 };

int main()
{
    //
    // What is the value of state variable 1 and state variable 2 ?
    //
    // YOUR ANSWER:
    //
    // state variable 1 = 
    // state variable 2 = 
    //
    // YOUR EXPLANATION:
    //
    //
    //
    //
    //

    int ret;

    struct state* s;

    s = states[0];

    s = states[ execute_state_machine( s, EVENT_START_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_DURING_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_DURING_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_DURING_SIGNAL ) ];

    printf("Value of state variable 1: %d\n", state_variable_1);

    s = states[ execute_state_machine( s, EVENT_DONE_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_DONE_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_START_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_DURING_SIGNAL ) ];
    s = states[ execute_state_machine( s, EVENT_DURING_SIGNAL ) ];

    printf("Value of state variable 2: %d\n", state_variable_2);

    return 0;
}



