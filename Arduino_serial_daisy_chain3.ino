#include <avr/interrupt.h>
#include <avr/io.h>
char temp;

int flag;

void setup()
{
   pinMode(13, OUTPUT);  // configuring pin 13 as output
   UBRR0 = 103; // for configuring baud rate of 9600bps
   UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); 
// Use 8-bit character sizes
   UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);  
// Turn on the transmission, reception, and Receive interrupt     
   sei();// enable global interrupt
   flag=0;
}

void loop()
{
if (flag==3){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);    
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);    
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
}
else{
  ;
}



}

void USART_Transmit(unsigned char data)
{
  /* Wait for empty transmit buffer */
  while ( !( UCSR0A & (1<<UDRE0)) )
  ;
  /* Put data into buffer, sends the data */
  UDR0 = data;
}


ISR(USART_RX_vect)
{ 
 temp=UDR0;// read the received data byte in temp
 USART_Transmit(UDR0);
if (UDR0=='0')
{
  flag=0;
  }
  if (UDR0=='3')
{
  flag=3;
  }

}
