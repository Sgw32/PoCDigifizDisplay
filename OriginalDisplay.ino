
#define CLOCK_PIN 41
#define STROBE_CLOCK_PIN 40
#define DATA_PIN 8

#define CLOCK_PIN_NAME PG0
#define CLOCK_PORT PORTG

#define STROBE_CLOCK_PIN_NAME PG1
#define STROBE_CLOCK_PORT PORTG

#define DATA_PIN_NAME PH5
#define DATA_PORT PORTH

uint8_t tr_status = 0x00; // sending, clockbit, 000000
uint16_t data_cnt = 0;
uint16_t data_payload[33] = {56327, 5, 31744, 79, 24584, 18119, 8199, 17220, 132, 4, 0, 0, 48512, 23947, 59137, 45854, 0, 0, 63488, 65083, 6, 0, 64504, 65007, 6, 0, 0, 0, 0, 0, 0, 0, 8};
uint8_t bool_data_payload[520] = {
  
1,1,1,

0, 1, 0, 0, 1, 1, 1, 1, //first, second digit clock top 
1, 1, 1, 1, 1, 1, 1, 0, //third, fourth digit clock top 
0, 1, 1, 1, 1, 1, 0, 0, //tacho (1700-1900) + MFA
1, 1, 1, 1, 1, 1, 1, 1, //tacho (1000-1700) 
0, 1, 1, 0, 0, 1, 0, 1, //first and second digit clock bot
0, 1, 1, 1, 1, 0, 1, 1, //third and fourth digit clock bot
1, 1, 1, 0, 1, 0, 0, 0, //tacho (5100-5200) + MFA
1, 1, 1, 1, 1, 1, 1, 1, //tacho (6000-5300)
1, 1, 1, 1, 1, 1, 1, 1, //tacho (0-700)
1, 1, 0, 0, 0, 0, 0, 0, //tacho(800-900)) + mileage(1-2)
1, 1, 1, 1, 0, 1, 1, 1, //mileage(3-4)
1, 1, 0, 1, 0, 1, 0, 0, //mileage(5-6)
1, 1, 1, 1, 1, 1, 1, 1, //tacho (7000-6300)
1, 1, 0, 0, 0, 0, 0, 0, //tacho (6200-6100) + mileage(1-2)
1, 1, 0, 0, 0, 1, 0, 1, //mileage (3-4)  
0, 1, 1, 1, 0, 1, 1, 0, //mileage (5-6)
1, 1, 1, 1, 1, 1, 1, 1, //fuel second digit, coolant T (9-10)
1, 1, 1, 1, 1, 1, 1, 1, //coolant T(1-8)
1, 1, 1, 1, 1, 1, 1, 1, //tacho(3400-2800)
1, 1, 1, 1, 1, 1, 1, 1, //tacho(2700-2000)
1, 1, 1, 1, 1, 1, 1, 1, //fuel down, coolant T(11-12)
1, 1, 1, 1, 1, 1, 1, 1, //coolant T(13-20)
0, 1, 1, 1, 1, 1, 1, 1, //refuel sign, tacho(3600-4200)
1, 1, 1, 1, 1, 1, 1, 1, //tacho(4300-5000)
0, 1, 1, 1, 1, 1, 1, 1, //mfa (1,2 digit top)
1, 0, 0, 0, 1, 1, 1, 1, //mfa (dot, 3,4)
1, 0, 0, 0, 1, 0, 1, 1, //mfa (4), speed (3)
1, 0, 1, 1, 0, 1, 0, 0, //speed(1-2), fuel(1 top)
0, 1, 1, 1, 0, 1, 1, 1, //mfa bottom 1,2
1, 0, 1, 1, 1, 0, 1, 1, //mfa float dot, mfa bot 3,4
1, 0, 0, 0, 1, 1, 1, 1, //mfa bot 4, speed top 3
1, 1, 1, 1, 1, 1, 0, 1, //speed 2-1 top, tacho, fuel shit and etc
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 0, 0, 0, 1, 1, 
1, 1, 1, 1, 1, 0, 1, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 
1, 0, 1, 1, 1, 1, 0, 1, 
1, 1, 1, 1, 1, 0, 1, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1,1,1,1,1};

void initDisplayClockTimer()
{
  // TIMER 1 for interrupt frequency 32786.88524590164 Hz:
  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 32786.88524590164 Hz increments
  OCR1A = 243; // = 16000000 / (1 * 32786.88524590164) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 1 prescaler
  TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interruptsinterrupts
}

ISR(TIMER1_COMPA_vect){ //~64 kHz
   //interrupt commands for TIMER 0 here
   if ((tr_status&0x40)==0) 
   {
      //transmission for clock
      if (CLOCK_PORT&(1<<CLOCK_PIN_NAME)) //-----|_____
      {
        CLOCK_PORT&=~(1<<CLOCK_PIN_NAME);
        if ((tr_status&0x10)==0)
          STROBE_CLOCK_PORT|=(1<<STROBE_CLOCK_PIN_NAME);
        else
        {
          DATA_PORT |= (1<<DATA_PIN_NAME);
          delayMicroseconds(16);
          DATA_PORT&=~(1<<DATA_PIN_NAME);
        }
      }
      else //______|-------
      {
        if (((tr_status&0x20)==0)&&((tr_status&0x10)==0))
        {
          STROBE_CLOCK_PORT|=(1<<STROBE_CLOCK_PIN_NAME);
        }
        CLOCK_PORT|=(1<<CLOCK_PIN_NAME);
        if (tr_status&0x20)
        {
          tr_status&=~0x20;
          tr_status|=0x10;
          delayMicroseconds(8);
          STROBE_CLOCK_PORT&=~(1<<STROBE_CLOCK_PIN_NAME);
          delayMicroseconds(2);
          DATA_PORT&=~(1<<DATA_PIN_NAME);
        }
        else if (tr_status&0x10)
        {
          tr_status&=~0x10;
          DATA_PORT |= (1<<DATA_PIN_NAME);
          delayMicroseconds(8);
          STROBE_CLOCK_PORT|=(1<<STROBE_CLOCK_PIN_NAME);
        }
      }
      
      if (tr_status&0x80)
      {
        delayMicroseconds(8);
        if (data_cnt==3)
        {
          DATA_PORT&=~(1<<DATA_PIN_NAME);
        }
        if (data_cnt==515)
        {
          DATA_PORT |= (1<<DATA_PIN_NAME);
        }
      }
   }
   else
   {
      //middle transition for strobe
      if (tr_status&0x80)
      {
        STROBE_CLOCK_PORT&=~(1<<STROBE_CLOCK_PIN_NAME); //16 kHz

        //STROBE_CLOCK is always falling here (STROBE_CLOCK_PIN = 0) at this time
        if (data_cnt>250)
        {
          delayMicroseconds(8);
          if (bool_data_payload[data_cnt])
          {
            DATA_PORT |= (1<<DATA_PIN_NAME); 
          }
          else
          {
            DATA_PORT &= ~(1<<DATA_PIN_NAME);
          }
        }
        else
        {
          if (millis()<5000)
          {
            delayMicroseconds(8);
            if (random(0,10)>5)
            {
              DATA_PORT |= (1<<DATA_PIN_NAME); 
            }
            else
            {
              DATA_PORT &= ~(1<<DATA_PIN_NAME);
            }
          }
          else
          {
            if (data_cnt>3)
            {
              delayMicroseconds(8);
              if (bool_data_payload[data_cnt])
              {
                DATA_PORT |= (1<<DATA_PIN_NAME); 
              }
              else
              {
                DATA_PORT &= ~(1<<DATA_PIN_NAME);
              }
            }
          }
        }
        data_cnt++;
        if (data_cnt==516)
        {
          data_cnt = 0;
          tr_status &= ~0x80;
          DATA_PORT |= (1<<DATA_PIN_NAME);
        }
      }
   }
   tr_status ^= 0x40; //32 kHz
} 

void init_digifiz()
{
  tr_status|=0x20;
}


void setup() {
  // put your setup code here, to run once:
  initDisplayClockTimer(); //~32786 Hz
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(STROBE_CLOCK_PIN,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
  digitalWrite(CLOCK_PIN,HIGH);
  digitalWrite(STROBE_CLOCK_PIN,HIGH);
  digitalWrite(DATA_PIN,HIGH);

  //Clock started
  delay(50);//as in Digifiz, 50 ms delay
  init_digifiz();
  delay(600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(70);
  if (!(tr_status&0x80))
    tr_status|=0x80;
  delay(70);
  if (!(tr_status&0x80))
    tr_status|=0x80;
}
