/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-08     obito0   first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED0 pin: PC13 */
#define LED0_PIN            GET_PIN(C, 13)
/* defined the Relay Module pin: PB9 */
#define RELAY_MODULE_PIN    GET_PIN(B, 9)

int main(void)
{
    int count = 1;
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);

    while (count++)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}

void led_on(void)
{
    rt_pin_mode(RELAY_MODULE_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(RELAY_MODULE_PIN, PIN_LOW);
    // rt_kprintf("turn on the led\n");
    // rt_kprintf("status of pin: %d\n", rt_pin_read(RELAY_MODULE_PIN));
}
MSH_CMD_EXPORT(led_on, turn on the led);

void led_off(void)
{
    rt_pin_mode(RELAY_MODULE_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(RELAY_MODULE_PIN, PIN_HIGH);
    // rt_kprintf("turn off the led\n");
    // rt_kprintf("status of pin: %d\n", rt_pin_read(RELAY_MODULE_PIN));
}
MSH_CMD_EXPORT(led_off, turn off the led);
