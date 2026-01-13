#include <stdint.h>
#include <stdio.h>

#define STATE_STATUS_ENTRY          0
#define STATE_STATUS_DURING         1
#define STATE_STATUS_EXIT           2

#define EVENT_START_SIGNAL          0
#define EVENT_DURING_SIGNAL         1
#define EVENT_DONE_SIGNAL           2

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
    // state variable 1 = 3
    // state variable 2 = 98
    //
    // YOUR EXPLANATION:
    //
    // PART 1: STATE 1 EXECUTION (Increment Logic)
    // 1. Initial State: Pointer 's' points to State 1 (Index 0). Status is ENTRY. Var1 is 0.
    // 2. Call 1 (START): Hits state_1_entry. Updates status to DURING. Returns 0.
    // 3. Call 2 (DURING): Hits state_1_during. Increments Var1 (0 -> 1). Returns 0.
    // 4. Call 3 (DURING): Hits state_1_during. Increments Var1 (1 -> 2). Returns 0.
    // 5. Call 4 (DURING): Hits state_1_during. Increments Var1 (2 -> 3). Returns 0.
    // -> Result: state_variable_1 is 3.
    //
    // PART 2: THE TRANSITION
    // 6. Call 5 (DONE): Hits state_1_during. Detects DONE signal. Updates status to EXIT.
    // 7. Call 6 (DONE): Hits state_1_exit. Returns (state->state + 1) which is 1.
    // -> Result: Pointer 's' updates to states[1] (State 2).
    //
    // PART 3: STATE 2 EXECUTION (Decrement Logic)
    // 8. Call 7 (START): Hits state_2_entry. Sets Var2 = 100. Updates status to DURING. Returns 1.
    // 9. Call 8 (DURING): Hits state_2_during. Decrements Var2 (100 -> 99). Returns 1.
    // 10. Call 9 (DURING): Hits state_2_during. Decrements Var2 (99 -> 98). Returns 1.
    // -> Result: state_variable_2 is 98.
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
