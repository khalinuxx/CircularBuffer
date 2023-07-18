#include"CircularBuffer.h"


int main()
{
    CircularBufferWrite("TEST ETH1 1", 10, ETH);
    CircularBufferRead(ETH);

    CircularBufferWrite("TEST USB 1", 10, USB);
    CircularBufferRead(USB);

    return 0;
}