#include "SerialClass.h" // Library described above

// application reads from the specified serial port and reports the collected data
int main()
{
    printf("Welcome to the serial test app!\n\n");

    Serial *SP = new Serial("\\\\.\\COM13"); // adjust as needed

    if (SP->IsConnected())
    cout << "We're connected";
    cout << "\n";

    char incomingData[256] = ""; // don't forget to pre-allocate memory
    // printf("%s\n",incomingData);
    int dataLength = 255;
    int readResult = 0;

    while (SP->IsConnected())
    {
        readResult = SP->ReadData(incomingData, dataLength);
        // printf("Bytes read: (0 means no data available) %i\n",readResult);
        incomingData[readResult] = 0;

        cout << incomingData;

        Sleep(500);
    }
    return 0;
}