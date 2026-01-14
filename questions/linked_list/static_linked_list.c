
#include <stdio.h>
#include <stdint.h>

struct list_element
{
    struct list_element* next;
    struct list_element* previous;
    void* element;
};

//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//
//

struct list_element* list_element_add(struct list_element* list, struct list_element* list_element, void* element)
{
    struct list_element* temp;
    struct list_element* next;

    if( ( list->next == NULL ) && ( list->previous == NULL ) )
    {
        temp = list;
        
        list_element->element = element;
        list_element->previous = list;
        list_element->next = NULL;

        list->next = list_element;
        list->previous = NULL;
        next = list->next;
        next->element = element;
        next->previous = temp;
    }
    else
    {
        temp = list;

        list_element->previous = list;
        list_element->element = element;
        list_element->next = NULL;

        list->next = list_element;
        next = list->next;
        next->previous = temp;
    }

    return next;
}

//
// What does this function do?
//
// YOUR EXPLANATION (mandatory):
//
//
//

static struct list_element* list_get_head(struct list_element* element)
{
    struct list_element* cur = element;

    while (cur->previous->previous != NULL)
    {
        cur = cur->previous;
    }

    return cur;
}

//
// What does this function do?
//
// YOUR EXPLANATION (mandatory):
//
//
//

static struct list_element* list_get_tail(struct list_element* element)
{
    struct list_element* temp;

    temp = element;

    while( temp->next != NULL )
    {
        temp = temp->next;
    }

    return temp;
}

//
// What does this function do?
//
// YOUR EXPLANATION (mandatory):
//
//
//

static struct list_element* list_move_towards_head(struct list_element* element)
{
    return element->previous;
}

//
// What does this function do?
//
// YOUR EXPLANATION (mandatory):
//
//
//

static struct list_element* list_move_towards_tail(struct list_element* element)
{
    return element->next;
}

//
// What does this function do?
//
// YOUR EXPLANATION (mandatory):
//
//
//

static struct list_element* list_remove_from_head(struct list_element* element)
{
    struct list_element* head;
    struct list_element* previous;

    head = list_get_head(element);

    previous = head->previous;

    head->next->previous = head->previous;
    head->previous->next = head->next;

    head->next = NULL;
    head->previous = NULL;

    return(element);
}

//
// What does this function do?
//
// YOUR EXPLANATION (mandatory):
//
//
//

static struct list_element* list_remove_from_tail(struct list_element* element)
{
    struct list_element* tail_element;

    tail_element = list_get_tail(element);

    tail_element->previous->next = NULL;
    tail_element = tail_element->previous;

    return tail_element;
}

//
// What does this function do?
//
// Your explanation:
//
//
//

int list_size(struct list_element* element)
{
    int size = 0;

    struct list_element* head;

    head = list_get_head(element);

    while(head != NULL)
    {
        size++;
        head = head->next;
    }

    return size;
}

//
// What does this function do?
//
// Your explanation:
//
//
//

void list_print(struct list_element* element)
{
    struct list_element* head;

    head = list_get_head(element);

    printf("Static linked list:\n\n");

    int index = 0;

    while(head != NULL)
    {
        printf("Element %d: %d\n", index, *((uint8_t*)head->element));
        head = head->next;
    }

    printf("\n\n");
}

#define DEREFERENCE_PTR_TO_TYPE(x, type)        *((type*)(x))

int main()
{
    static struct list_element list;
    static struct list_element* plist = &list;

    static uint8_t element_1 = 1;
    static uint8_t element_2 = 2;
    static uint8_t element_3 = 3;
    static uint8_t element_4 = 4;
    static uint8_t element_5 = 5;
    static uint8_t element_6 = 6;

    static struct list_element list_element_1 = {0};
    static struct list_element list_element_2 = {0};
    static struct list_element list_element_3 = {0};
    static struct list_element list_element_4 = {0};
    static struct list_element list_element_5 = {0};
    static struct list_element list_element_6 = {0};

    plist = list_element_add( &list, &list_element_1, &element_1 );
    plist = list_element_add( plist, &list_element_2, &element_2 );
    plist = list_element_add( plist, &list_element_3, &element_3 );
    plist = list_element_add( plist, &list_element_4, &element_4 );
    plist = list_element_add( plist, &list_element_5, &element_5 );

    //  What is the output of this program?

    printf("Value of latest element added to list: %d\n", DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));

    //  What is the output of this program ?

    plist = list_get_tail(plist);
    printf("Value of tail element: %x\n", DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));

    //  What is the output of this program ?

    plist = list_get_head(plist);
    printf("Value of head element: %x\n", DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));

    // What is the output of this program ?

    plist = list_move_towards_tail(plist);
    plist = list_move_towards_tail(plist);

    printf("Output element after moving towards the tail 2 times: %d\n", \
        DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));

    //
    // What is the output of this program?
    //
    // Your answer & explanation (mandatory)
    //
    //
    //

    plist = list_remove_from_head(plist);
    plist = list_get_head(plist);
    printf("Value of head element: %x\n", DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));

    //
    // What is the output of this program?
    //
    // Your answer & explanation (mandatory)
    //
    //
    //

    plist = list_get_tail(plist);
    printf("Value of tail before deletion of tail: %d\n", DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));
    plist = list_remove_from_tail(plist);
    printf("Value of tail before deletion of tail: %d\n", DEREFERENCE_PTR_TO_TYPE(plist->element, uint8_t));
 
    //
    // What is the output of this program?
    //
    // Your answer and explanation:
    //
    //

    printf("Size of list: %d\n", list_size(plist));

    //
    // What is the output of this program?
    //
    // Your answer and explanation:
    //
    //

    list_print(plist);
    plist = list_element_add( plist, &list_element_6, &element_6 );
    list_print(plist);

    return 0;
}