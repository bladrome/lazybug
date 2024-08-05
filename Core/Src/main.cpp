#include "ebox.h"
#include "math.h"
#include "bsp_ebox.h"

#define EXAMPLE_NAME	"Analog_Write example"
#define EXAMPLE_DATE	"2018-08-05"


Pwm p(&PB8);

void setup()
{
    ebox_init();

    p.begin(4000, 0);
    p.set_oc_polarity(1);
    UART.begin(115200);
    print_log(EXAMPLE_NAME, EXAMPLE_DATE);
}


int main(void)
{

    setup();

    uint32_t duty = 1000;
    float x;
    uint16_t y;
    while(1)
    {
        x = x + PI * 0.01;
        if(x >= PI)x = 0;

        y = duty * sin(x);

        p.set_duty(y);
        delay_ms(10);
    }
}
