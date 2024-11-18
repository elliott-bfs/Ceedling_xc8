#include "support_uart.h"

void simulatorStart(void)
{
    support_init_uart();
}

/**
 * @brief Quit the simulator
 */
void simulatorQuit(void)
{
    while (1) { }
}