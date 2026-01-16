
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define CIRCULAR_BUFFER_OK              0
#define CIRCULAR_BUFFER_OVERFLOW        1
#define CIRCULAR_BUFFER_UNDERFLOW       2

struct circular_buffer
{
    int read_index;
    int write_index;
    const int element_size;
    int element_count;
    int status;
    void* buffer;
    const size_t buffer_size;
};

void circular_buffer_init(struct circular_buffer* buffer)
{
    memset( buffer->buffer, 0, buffer->buffer_size );

    buffer->status = CIRCULAR_BUFFER_OK;
    buffer->element_count = 0;
    buffer->read_index = 0;
    buffer->write_index = 0;
}

//
// Explain what this function does
//
//
//
//
//

int circular_buffer_write(struct circular_buffer* buffer, void* element)
{
    if( ( buffer->element_count >= buffer->buffer_size ) && ( buffer->read_index == buffer->write_index ) )
    {
        buffer->status = CIRCULAR_BUFFER_OVERFLOW;
        return CIRCULAR_BUFFER_OVERFLOW;
    }

    memcpy( ((uint8_t*)buffer->buffer) + (buffer->write_index*(int)buffer->element_size),  \
            (uint8_t*)element,                                                             \
            buffer->element_size );
    
    buffer->write_index++;

    if( buffer->write_index >= (int)buffer->buffer_size )
    {
        buffer->write_index = 0;
    }

    buffer->status = CIRCULAR_BUFFER_OK;
    buffer->element_count++;

    return CIRCULAR_BUFFER_OK;
}

//
// Explain what this function does
//
//
//
//
//

int circular_buffer_read(struct circular_buffer* buffer, void* element)
{
    if( buffer->element_count == 0 )
    {
        buffer->status = CIRCULAR_BUFFER_UNDERFLOW;
        return CIRCULAR_BUFFER_UNDERFLOW;
    }

    memcpy( (uint8_t*)element,\
            ((uint8_t*)buffer->buffer) + (buffer->read_index*(int)buffer->element_size),\
            buffer->element_size );
    
    buffer->read_index++;
    buffer->element_count--;

    if( buffer->read_index >= buffer->buffer_size )
    {
        buffer->read_index = 0;
    }

    buffer->status = CIRCULAR_BUFFER_OK;
    return CIRCULAR_BUFFER_OK;
}

//
// Explain what this function does
//
//
//
//
//

#define CIRCULAR_BUFFER_STATUS_STRING(x)                                            \
    (x == 0) ? "OK" : ( ( x == 1) ? "OVEFLOW" : "UNDERFLOW" )

//
// Explain what this function does
//
//
//
//
//

#define CIRCULAR_BUFFER_PRINT_INFO(_buffer,type)                                    \
{                                                                                   \
    int index;                                                                      \
                                                                                    \
    printf("\n\nCircular buffer contents:\n\n");                                    \
                                                                                    \
    for( index = 0 ; index < _buffer.buffer_size ; index++ )                        \
    {                                                                               \
        printf("Element [%d] = %d\n", index, ((type*)_buffer.buffer)[index]);       \
    }                                                                               \
                                                                                    \
    printf("Circular buffer read index: %d\n", _buffer.read_index);                  \
    printf("Circular buffer write index: %d\n", _buffer.write_index);                \
    printf("Circular buffer status: %s\n", CIRCULAR_BUFFER_STATUS_STRING(_buffer.status) );            \
    printf("Circular buffer size: %d\n", _buffer.buffer_size);                                         \
    printf("Circular buffer element size: %d\n", _buffer.element_size);                 \
    printf("\n\n");                                                                                    \
}

static uint8_t buffer[8];

int main(void)
{
    static struct circular_buffer circular_buffer = 
    {
        .buffer         = buffer,
        .buffer_size    = sizeof(buffer),
        .element_size   = sizeof(buffer[0]),
    };

    static uint8_t element = 1;
    int index = 0;

    circular_buffer_init(&circular_buffer);

    for( index = 0 ; index < 5 ; index++ )
    {
        element = (2*index*index) + (10*index) + 5;
        circular_buffer_write(&circular_buffer, &element);
    }

    CIRCULAR_BUFFER_PRINT_INFO(circular_buffer,uint8_t);

    for( index = 0 ; index < 3 ; index++ )
    {
        circular_buffer_read( &circular_buffer, &element );
    }

    CIRCULAR_BUFFER_PRINT_INFO(circular_buffer, uint8_t);

    for( index = 0 ; index < 1 ; index++ )
    {
        element = 1;

        circular_buffer_write(&circular_buffer, &element);
    }

    CIRCULAR_BUFFER_PRINT_INFO(circular_buffer, uint8_t);

    return 0;
}