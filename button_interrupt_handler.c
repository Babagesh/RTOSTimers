#include "FreeRTOS.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "timers.h"


extern TimerHandle_t timer2_handle;
extern TimerHandle_t timer1_handle;
void sl_button_on_change(const sl_button_t * handle)
{
  if(handle == &sl_button_btn0)
    {
      if(xTimerIsTimerActive(timer1_handle))
      {
        sl_led_turn_off(&sl_led_led0);
        xTimerStopFromISR(timer1_handle, portMAX_DELAY);
      }
    else
      {
        xTimerStartFromISR(timer1_handle, portMAX_DELAY);
      }
    }
  else
    {

    }
}





