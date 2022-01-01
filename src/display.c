/*
 * Adapted from demo for ssd1306 i2c driver for Raspberry Pi 
 *
 * Does all of the usual, plus:
 * - Bitcoind status
 * - LND/lncli status
 */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "ssd1306_i2c.h"
#include "time.h"
#include <unistd.h>

// sig_handler clears the screen and exits
void sig_handler(int sig) {
  OLED_Clear();
  signal(sig, SIG_DFL);
  raise(sig);
}

int main(void) 
{
  unsigned char symbol=0;

  ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);

  if (i2cd<0)
    {
      printf("I2C device failed to open\r\n");
      return 0;
    }

  //Short delay Ensure the normal response of the lower function
  usleep(150*1000);

  //Get IP address
  FirstGetIpAddress();

  signal(SIGINT, sig_handler);

  while(1)
    {
      if (LCD_Display(symbol)) {
	sleep(1);
	sleep(1);
	sleep(1);
      }
      symbol++;

      if(symbol==4)
        {
          symbol=0;
        }
    }
  return 0;
}
