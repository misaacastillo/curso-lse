#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

#include "app_tasks.h"

/**
 * @brief Programa principal
 */
int main(void) {
	// Clock del sistema a 30 MHz
	BOARD_BootClockFRO30M();
	BOARD_InitDebugConsole();

	// Creacion de tareas

	// tarea de inicializacion
	xTaskCreate(task_init, "Init", tskINIT_STACK, NULL, tskINIT_PRIORITY, NULL);
	// tarea adc
	xTaskCreate(task_adc, "ADC", tskADC_STACK, NULL, tskADC_PRIORITY, NULL);
	// tarea de display
	xTaskCreate(task_display, "Display", tskDISPLAY_STACK, NULL, tskDISPLAY_PRIORITY, &handle_display);
	// tarea de cambio de display con user
	xTaskCreate(task_display_change, "Display change", tskDISPLAY_CHANGE_STACK, NULL, tskDISPLAY_CHANGE_PRIORITY, NULL);
	// tarea user button
	xTaskCreate(task_userbtn, "user button", tskUSERBTN_STACK, NULL, tskUSERBTN_PRIORITY, NULL);
	// tarea de led rgb
	xTaskCreate(task_ledrgb, "Led RGB", tskLEDRGB_STACK, NULL, tskLEDRGB_PRIORITY, NULL);
	// tarea pwm
	xTaskCreate(task_pwm, "PWM", tskPWM_STACK, NULL, tskPWM_PRIORITY, NULL);
	// tarea bh1750
	xTaskCreate(task_bh1750, "BH1750", tskBH1750_STACK, NULL, tskBH1750_PRIORITY, NULL);
	// tarea buzzer
	xTaskCreate(task_buzzer, "Buzzer", tskBUZZER_STACK, NULL, tskBUZZER_PRIORITY, NULL);
	// contador con botones
	xTaskCreate(task_cnt_bt, "Counter Buttons", tskCNT_BT_STACK, NULL,tskCNT_BT_PRIORITY, NULL);
	// tarea de timer
	xTaskCreate(task_ShowValues, "Timer", tskTIMER_STACK, NULL,tskTIMER_PRIORITY, NULL);

	vTaskStartScheduler();
}