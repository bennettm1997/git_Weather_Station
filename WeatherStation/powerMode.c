/*In low power mode we will decrease the ADC sampling rate to a minimum. - Change the capture compare register to a lower value, to decrease the sampling rate.
 * In High power mode we will sample at the fastest rate we can within reason.
 *
 */
void low_Power(){
//set clock to have a frequency of 60 secs. and pull data at this time


}
void high_Power(){
	//set clock to have a frequency of 10 secs. and pull data at this time
}

int Check_Power(){
	if(BUTTON == BUTTONPUSHLOW){
		return BUTTONPUSHLOW;
	}
	if(BUTTON == BUTTONPUSHHIGH){
		return BUTTONPUSHHIGH;
	}
	if(BUTTON == BUTTONPUSHOFF){
		return BUTTONPUSHOFF;
	}
}


