

// Circular Buffer Header Buffer

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

// includes 
#include <stdint.h>

// enum declaration 
enum CB
{
    ETH = 0,
    USB
};

// functions prototypes
uint8_t *GetCircularBufferAddrToRead(uint8_t CB);
void CircularBufferRead(uint8_t CB);
void CircularBufferWrite(void *source, size_t size, uint8_t CB);



#endif    //CIRCULARBUFFER_H_