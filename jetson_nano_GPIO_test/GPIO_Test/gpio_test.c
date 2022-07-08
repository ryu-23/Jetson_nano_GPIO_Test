#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#define LED_GPIO_DIR "/sys/class/gpio"

int main(){
 int  port_num = 216, value, i;
 char buff[256];
 FILE *fp;

 snprintf(buff,sizeof(buff),"%s/export",LED_GPIO_DIR);
 fp = fopen(buff,"w");
 fprintf(fp,"%d\n",port_num);
 fclose(fp);

 snprintf(buff,sizeof(buff),"%s/gpio%d/direction",LED_GPIO_DIR,port_num);
 fp = fopen(buff,"w");
 fprintf(fp,"out\n");
 fclose(fp);

 snprintf(buff,sizeof(buff),"%s/gpio%d/value",LED_GPIO_DIR,port_num);
 fp = fopen(buff,"w");
 setvbuf(fp, NULL, _IONBF, 0);
  
 value = 0;
 for(i=0;i<=100;i++){
  fprintf(fp,"%d\n",value);
  sleep(1);
  value = !value;
 }
 fclose(fp);

 snprintf(buff,sizeof(buff),"%s/unexport",LED_GPIO_DIR);
 fp = fopen(buff,"w");
 fprintf(fp,"%d\n",port_num);
 fclose(fp);

 return 0;
}
