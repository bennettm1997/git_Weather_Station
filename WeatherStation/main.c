
#include "msp.h"
#include "system_Configure.h"
#include "packetizeData.h"
#include "send_Log.h"
#include "powerMode.h"
void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
    configure_All(); //change to configure all later

    /*
     *
     * We will need a button interrupt handler for this. Continusously checking for button presses will use a lot of resources
     *
#DEFINE BUTTONPUSHLOW 1;
#DEFINE BUTTONPUSHHIGH 1;
#DEFINE BUTTONPUSHOFF  1;
    BUTTON = BUTTONPUSHLOW;
    while(BUTTON == BUTTONPUSHLOW){
    	low_Power();
    	Check_Power();
    }
    while(BUTTON == BUTTONPUSHHIGH){
    	high_Power();
    	Check_Power();
    }
    while(BUTTON == BUTTONPUSHOFF){
    	return 0;
    }
    */


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
