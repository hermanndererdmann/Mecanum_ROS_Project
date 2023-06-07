
#ifndef __MAINPP_H
#define __MAINPP_H
//

#ifdef __cplusplus


#include "main.h"

extern "C" {
#endif


void setup(void);
void loop(void);

void cmd_vel(const geometry_msgs::Twist& msg);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif /* __MAINPP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

