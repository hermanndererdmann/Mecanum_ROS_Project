/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M4_IN0_Pin GPIO_PIN_13
#define M4_IN0_GPIO_Port GPIOC
#define LED_GREEN_Pin GPIO_PIN_0
#define LED_GREEN_GPIO_Port GPIOH
#define LED_RED_Pin GPIO_PIN_1
#define LED_RED_GPIO_Port GPIOH
#define BAT1_4_Pin GPIO_PIN_0
#define BAT1_4_GPIO_Port GPIOC
#define BAT1_3_Pin GPIO_PIN_1
#define BAT1_3_GPIO_Port GPIOC
#define BAT1_5_Pin GPIO_PIN_2
#define BAT1_5_GPIO_Port GPIOC
#define BAT1_6_Pin GPIO_PIN_3
#define BAT1_6_GPIO_Port GPIOC
#define BAT2_6_Pin GPIO_PIN_0
#define BAT2_6_GPIO_Port GPIOA
#define PWM_M4_Pin GPIO_PIN_1
#define PWM_M4_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define BAT1_1_Pin GPIO_PIN_4
#define BAT1_1_GPIO_Port GPIOA
#define PWM_M1_Pin GPIO_PIN_5
#define PWM_M1_GPIO_Port GPIOA
#define BAT2_2_Pin GPIO_PIN_6
#define BAT2_2_GPIO_Port GPIOA
#define BAT2_3_Pin GPIO_PIN_7
#define BAT2_3_GPIO_Port GPIOA
#define BAT2_5_Pin GPIO_PIN_4
#define BAT2_5_GPIO_Port GPIOC
#define BAT2_1_Pin GPIO_PIN_5
#define BAT2_1_GPIO_Port GPIOC
#define BAT1_2_Pin GPIO_PIN_0
#define BAT1_2_GPIO_Port GPIOB
#define BAT2_4_Pin GPIO_PIN_1
#define BAT2_4_GPIO_Port GPIOB
#define Encoder1_Pin GPIO_PIN_2
#define Encoder1_GPIO_Port GPIOB
#define Encoder1_EXTI_IRQn EXTI2_IRQn
#define PWM_M2_Pin GPIO_PIN_10
#define PWM_M2_GPIO_Port GPIOB
#define Encoder2_Pin GPIO_PIN_12
#define Encoder2_GPIO_Port GPIOB
#define Encoder2_EXTI_IRQn EXTI15_10_IRQn
#define M1_IN0_Pin GPIO_PIN_6
#define M1_IN0_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_7
#define B1_GPIO_Port GPIOC
#define PWM_Servo_Pin GPIO_PIN_8
#define PWM_Servo_GPIO_Port GPIOC
#define M1_IN1_Pin GPIO_PIN_9
#define M1_IN1_GPIO_Port GPIOC
#define LED_White_Pin GPIO_PIN_13
#define LED_White_GPIO_Port GPIOA
#define Encoder4_Pin GPIO_PIN_14
#define Encoder4_GPIO_Port GPIOA
#define Encoder4_EXTI_IRQn EXTI15_10_IRQn
#define Encoder3_Pin GPIO_PIN_10
#define Encoder3_GPIO_Port GPIOC
#define Encoder3_EXTI_IRQn EXTI15_10_IRQn
#define M4_IN1_Pin GPIO_PIN_11
#define M4_IN1_GPIO_Port GPIOC
#define M3_IN0_Pin GPIO_PIN_12
#define M3_IN0_GPIO_Port GPIOC
#define M3_IN1_Pin GPIO_PIN_2
#define M3_IN1_GPIO_Port GPIOD
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
