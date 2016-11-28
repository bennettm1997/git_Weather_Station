
#include "msp.h"
#include "system_Configure.h"
#include "packetizeData.h"
#include "send_Log.h"
void main(void)
{
	hi
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
    configure_All(); //change to configure all later


    Weather_Packet packet;
    fill_Packet(&packet);
    sendLog("What is the sq rtts");
    int i;
    //tests sending data over bluetooth
    for(i = 0; i<10; i++){
    	sendAPacket(&packet);//sends the packet
    }

}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
