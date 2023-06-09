/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void setup(void);
void loop(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M4_IN0_Pin GPIO_PIN_13
#define M4_IN0_GPIO_Port GPIOC
#define PWM_M4_Pin GPIO_PIN_1
#define PWM_M4_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define PWM_M1_Pin GPIO_PIN_5
#define PWM_M1_GPIO_Port GPIOA
#define Encoder1_Pin GPIO_PIN_2
#define Encoder1_GPIO_Port GPIOB
#define Encoder1_EXTI_IRQn EXTI2_IRQn
#define PWM_M2_Pin GPIO_PIN_10
#define PWM_M2_GPIO_Port GPIOB
#define Encoder2_Pin GPIO_PIN_12
#define Encoder2_GPIO_Port GPIOB
#define M1_IN0_Pin GPIO_PIN_6
#define M1_IN0_GPIO_Port GPIOC
#define M1_IN1_Pin GPIO_PIN_9
#define M1_IN1_GPIO_Port GPIOC
#define M3_IN1_Pin GPIO_PIN_8
#define M3_IN1_GPIO_Port GPIOA
#define Encoder4_Pin GPIO_PIN_11
#define Encoder4_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_12
#define LED_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define Encoder3_Pin GPIO_PIN_10
#define Encoder3_GPIO_Port GPIOC
#define M4_IN1_Pin GPIO_PIN_11
#define M4_IN1_GPIO_Port GPIOC
#define M3_IN0_Pin GPIO_PIN_12
#define M3_IN0_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define PWM_M3_Pin GPIO_PIN_4
#define PWM_M3_GPIO_Port GPIOB
#define M2_IN1_Pin GPIO_PIN_6
#define M2_IN1_GPIO_Port GPIOB
#define M2_IN0_Pin GPIO_PIN_9
#define M2_IN0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
