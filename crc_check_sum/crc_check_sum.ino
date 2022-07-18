#define MAX_RECEIVE_DATA 20
#define SIZE_PACKET  13
union
{
    short data ;
    char  bytedata[2];
} m_int, m_crc;
union
{
    float data ;
    char  bytedata[4];
} m_float;
char receive_buff[MAX_RECEIVE_DATA] ={0,};
char send_buff[SIZE_PACKET+1] ={0,};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  send_int_data_1(1);
  delay(1000);
 send_int_data_2(1);
  delay(1000);
  send_int_data_3(1);
  delay(1000);
  send_int_data_4(1);
  delay(1000);
  send_int_data_5(1);
  delay(1000);
}
int crc_check(void)
{
  int crc=0;
  for(int i=1;i<6;i++)
  {
     send_buff[i];
     crc += send_buff[i];
  }
  return crc;
}
void send_int_data_1(int input)
{
   m_int.data = input;
   send_buff[0] = '#';
   send_buff[1] = 'I';
   send_buff[2] = 0;
   send_buff[3] = 2;
   send_buff[4] = 0;
   send_buff[5] = 0;
   send_buff[8] = '*';
   m_crc.data= crc_check();
   send_buff[6] = 0;
   send_buff[7] = 75;
   for(int i=0;i<SIZE_PACKET;i++)
   {
     Serial.print(send_buff[i]);
     send_buff[i] = 0;
   }
}

void send_int_data_2(int input)
{
   m_int.data = input;
   send_buff[0] = '#';
   send_buff[1] = '*';
   send_buff[2] = '#';
   send_buff[3] = 'I';
   send_buff[4] = 0;
   send_buff[5] = 2;
   send_buff[6] = 0;
   send_buff[7] = 0;
   send_buff[10] = '*';
   m_crc.data= crc_check();
   send_buff[8] = 0;
   send_buff[9] = 75;
   for(int i=0;i<SIZE_PACKET;i++)
   {
     Serial.print(send_buff[i]);
     send_buff[i] = 0;
   }
}

void send_int_data_3(int input)
{
   m_int.data = input;
   send_buff[0] = '#';
   send_buff[1] = '*';
   send_buff[2] = '#';
   send_buff[3] = 'I';
   send_buff[4] = 0;
   send_buff[5] = 2;
   send_buff[6] = 0;
   send_buff[7] = 0;
   send_buff[10] = '*';
   m_crc.data= crc_check();
   send_buff[8] = 0;
   send_buff[9] = 78;
   for(int i=0;i<SIZE_PACKET;i++)
   {
     Serial.print(send_buff[i]);
     send_buff[i] = 0;
   }
}

void send_int_data_4(int input)
{
   m_int.data = input;
   send_buff[0] = '#';
   send_buff[1] = '*';
   send_buff[2] = '#';
   send_buff[3] = 'I';
   send_buff[4] = 0;
   send_buff[5] = 5;
   send_buff[6] = 0;
   send_buff[7] = 0;
   send_buff[10] = '*';
   send_buff[11] = '*';
   m_crc.data= crc_check();
   send_buff[8] = 0;
   send_buff[9] = 78;
   for(int i=0;i<SIZE_PACKET;i++)
   {
     Serial.print(send_buff[i]);
     send_buff[i] = 0;
   }
}

void send_int_data_5(int input)
{
   m_int.data = input;
   send_buff[0] = '#';
   send_buff[1] = '*';
   send_buff[2] = '*';
   send_buff[3] = '*';
   send_buff[4] = '#';
   send_buff[5] = 'I';
   send_buff[6] = 0;
   send_buff[7] = 5;
   send_buff[8] = 0;
   send_buff[9] = 0;
   send_buff[10] = 0;
   send_buff[11] = 77;
   send_buff[12] = '*';
   send_buff[13] = '*';
   m_crc.data= crc_check();
   for(int i=0;i<SIZE_PACKET;i++)
   {
     Serial.print(send_buff[i]);
     send_buff[i] = 0;
   }
}
void loop() {
  // put your main code here, to run repeatedly:
}
