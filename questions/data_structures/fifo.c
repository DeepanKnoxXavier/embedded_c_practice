
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_OK                 0
#define FIFO_EMPTY              1
#define FIFO_FULL               2

struct fifo
{
    void*         buffer;
    const size_t  buffer_size;
    const size_t  element_size;
    int           element_count;
    int           status;
};

//
// Explain what this function does?
//
//
//
//

void fifo_init(struct fifo* fifo)
{
    fifo->element_count   = 0;
    fifo->status          = FIFO_OK;

    memset( fifo->buffer, 0, (int)fifo->buffer_size * (int)fifo->element_size );
}

//
// Explain what this function does?
//
//
//
//

int fifo_put(struct fifo* fifo, void* data)
{
    if( fifo->element_count == fifo->buffer_size )
    {
        fifo->status = FIFO_FULL;
        return FIFO_FULL;
    }

    memcpy( fifo->buffer + fifo->element_size * fifo->element_count , data, fifo->element_size );

    fifo->element_count++;
    fifo->status = FIFO_OK;

    return FIFO_OK;
}

//
// Explain what this function does?
//
//
//
//

int fifo_get(struct fifo* fifo, void* data)
{
    if( fifo->element_count == 0 )
    {
        fifo->status = FIFO_EMPTY;
        return fifo->status;
    }

    fifo->element_count--;
    memcpy( data, fifo->buffer + fifo->element_count * fifo->element_size, fifo->element_size );

    fifo->status = FIFO_OK;
    return FIFO_OK;
}

//
// Explain what this function does?
//
//
//
//

#define FIFO_PRINT_INFO(fifo, type)                                                             \
                                                                                                \
    printf("\n\nFIFO information\n\n");                                                         \
                                                                                                \
    printf("FIFO size: %d\n", fifo.buffer_size);                                                \
    printf("FIFO element size: %d\n", fifo.element_size);                                       \
    printf("FIFO status: %d\n\n", fifo.status);                                                 \
                                                                                                \
    for( int index = 0 ; index < fifo.element_size ; index++ )                                  \
    {                                                                                           \
        printf("Element %d: %d\n", index, *((type*)(fifo.buffer+fifo.element_size*index)));     \
    }                                                                                           \
                                                                                                \
    printf("\n\n");                                                                             \


static uint8_t buffer[64];

int main(void)
{
    static struct fifo fifo = {
        .buffer         = (void*)buffer,
        .buffer_size    = sizeof(buffer)/sizeof(int),
        .element_size   = sizeof(int),
    };

    static int element = 0;
    static int read_element = 0;

    fifo_init(&fifo);

    element = 10;
    fifo_put(&fifo, &element);

    element = 22;
    fifo_put(&fifo, &element);

    element = -29;
    fifo_put(&fifo, &element);

    //  What will be the output of this section ?

    FIFO_PRINT_INFO(fifo, int);

    fifo_get(&fifo, &read_element);

    // What will be the output of this section ?

    printf("Read element from FIFO: %d\n", read_element);

    //  What will be the output of this section ? 

    FIFO_PRINT_INFO(fifo, int);

    return 0;
}