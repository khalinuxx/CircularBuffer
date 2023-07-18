
// includes 
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//defines 
#define MAXSIZEETH 1518  // ETH BUFFER LENGTH
#define MAXBUFFSIZE 2048 // USB BUFFER LENGTH
#define CIRCBUFFSIZE 5   // CIRCULAR BUFFER LENGTH

#define ISETHBUFFEMPTY (EthCounter == 0)
#define ISETHBUFFULL (EthCounter == CIRCBUFFSIZE)

#define ISUSBBUFFEMPTY (UsbCounter == 0)
#define ISUSBBUFFULL (UsbCounter == CIRCBUFFSIZE)


// variables declaration
uint8_t EthBuffer[MAXSIZEETH * CIRCBUFFSIZE];  // buffer to store data recieved from ethernet
uint8_t UsbBuffer[MAXBUFFSIZE * CIRCBUFFSIZE]; // buffer to store data recieved from USB

uint8_t *WriteEthPtr = EthBuffer;
uint8_t *ReadEthPtr = EthBuffer;
unsigned int EthCounter = 0;

uint8_t *WriteUsbPtr = UsbBuffer;
uint8_t *ReadUsbPtr = UsbBuffer;
unsigned int UsbCounter = 0;

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




int main()
{
    CircularBufferWrite("TEST ETH 1", 10, ETH);
    CircularBufferRead(ETH);




    return 0;
}





uint8_t *GetCircularBufferAddrToRead(uint8_t CB)
{
    uint8_t *a = NULL;
    if (!CB)
    {

        // THE ETH READ SECTION
        if (ISETHBUFFEMPTY)
        {
            printf("The Ethernet Circular Buffer Is Empty \n");
            return NULL;
        }
        else
        {
            if ((WriteEthPtr != ReadEthPtr))
            {

                if ((ReadEthPtr - EthBuffer) == (MAXSIZEETH * CIRCBUFFSIZE))
                {
                    EthCounter--;
                    return (ReadEthPtr = EthBuffer);
                }
                else
                {
                    EthCounter--;
                    a = ReadEthPtr;
                    ReadEthPtr += MAXSIZEETH;
                    return a;
                }
            }
        }
    }

    else

    {
        // THE USB READ SECTION
        if (ISUSBBUFFEMPTY)
        {
            printf("The USB Circular Buffer Is Empty \n");
            return NULL;
        }
        else
        {
            if ((WriteUsbPtr != ReadUsbPtr))
            {
                if ((ReadUsbPtr - UsbBuffer) == (MAXBUFFSIZE * CIRCBUFFSIZE))
                {
                    UsbCounter--;
                    return (ReadUsbPtr = UsbBuffer);
                }
                else
                {
                    UsbCounter--;
                    a = ReadUsbPtr;
                    ReadUsbPtr += MAXBUFFSIZE;
                    return a;
                }
            }
        }
    }
}

void CircularBufferRead(uint8_t CB)
{
    uint8_t *a = NULL;
    a = GetCircularBufferAddrToRead(CB);
    printf("%s \n", a);

    if (!CB)
    {
        memset(a, '\0', MAXSIZEETH);
    }else
    {
        memset(a, '\0', MAXBUFFSIZE);}
}

void CircularBufferWrite(void *source, size_t size, uint8_t CB)
{
    if (!CB)
    {
        // THE ETH Write SECTION
        if (ISETHBUFFULL)
        {

            printf("The Ethernet Buffer is full \n");
        }
        else
        {
            memcpy(WriteEthPtr, source, size);

            ((WriteEthPtr - EthBuffer) == (MAXSIZEETH * CIRCBUFFSIZE)) ? (WriteEthPtr = EthBuffer) : (WriteEthPtr += MAXSIZEETH);

            EthCounter++;
        }
    }
    else
    {
        // THE USB Write SECTION
        if (ISUSBBUFFULL)
        {

            printf("The USB Buffer is full \n");
        }
        else
        {
            memcpy(WriteUsbPtr, source, size);
            ((WriteUsbPtr - UsbBuffer) == (MAXBUFFSIZE * CIRCBUFFSIZE)) ? (WriteUsbPtr = UsbBuffer) : (WriteUsbPtr += MAXBUFFSIZE);

            UsbCounter++;
        }
    }
}