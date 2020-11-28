#include "hal.h"
#include "annepro2.h"
#include "qmk_ap2_led.h"

void annepro2LedDisable(void)
{
  sdPut(&SD0, CMD_LED_OFF);
}

void annepro2LedEnable(void)
{
  sdPut(&SD0, CMD_LED_ON);
}

void annepro2LedUpdate(uint8_t row, uint8_t col)
{
  sdPut(&SD0, CMD_LED_SET);
  sdPut(&SD0, row);
  sdPut(&SD0, col);
  sdWrite(&SD0, (uint8_t *)&annepro2LedMatrix[row * MATRIX_COLS + col], sizeof(uint16_t));
}

void annepro2LedUpdateRow(uint8_t row)
{
  sdPut(&SD0, CMD_LED_SET_ROW);
  sdPut(&SD0, row);
  sdWrite(&SD0, (uint8_t *)&annepro2LedMatrix[row * MATRIX_COLS], sizeof(uint16_t) * MATRIX_COLS);
}

void annepro2LedSetProfile(uint8_t prof)
{
  sdPut(&SD0, CMD_LED_SET_PROFILE);
  sdPut(&SD0, prof);
}

uint8_t annepro2LedGetProfile()
{
  uint8_t buf = 0;
  sdPut(&SD0, CMD_LED_GET_PROFILE);
  buf = sdGet(&SD0);
  return buf;
}

uint8_t annepro2LedGetNumProfiles()
{
  uint8_t buf = 0;
  sdPut(&SD0, CMD_LED_GET_NUM_PROFILES);
  buf = sdGet(&SD0);
  return buf;
}

void annepro2LedNextProfile()
{
  sdPut(&SD0, CMD_LED_NEXT_PROFILE);
}

void annepro2LedPrevProfile()
{
  sdPut(&SD0, CMD_LED_PREV_PROFILE);
}

void annepro2LedSetMask(uint8_t key)
{
  sdPut(&SD0, CMD_LED_SET_MASK);
  sdPut(&SD0, key);
}

void annepro2LedClearMask(uint8_t key)
{
  sdPut(&SD0, CMD_LED_CLEAR_MASK);
  sdPut(&SD0, key);
}

void annepro2LedSetForeColor(uint8_t red, uint8_t green, uint8_t blue)
{
  sdPut(&SD0, CMD_LED_SET_FORECOLOR);
  uint8_t colors[3]={red,green,blue};
  sdWrite(&SD0, (uint8_t *)&colors, sizeof(uint8_t)*3);
}

void annepro2LedResetForeColor()
{
  sdPut(&SD0, CMD_LED_RESET_FORECOLOR);
}

