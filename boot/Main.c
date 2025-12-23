#include "stdint.h"
#include "stdbool.h"
#include "HalUart.h"
#include "HalInterrupt.h"
#include "stdio.h"
#include "HalTimer.h"
#include "stdlib.h"
#include "task.h"
static void Hw_init();
static void Printf_test();
static void Timer_test();

void User_task0();
void User_task1();
void User_task2();

void main(void)
{
    Hw_init();
    
    uint32_t i =100;
    while(i--){
        Hal_uart_put_char('N');
    }
    Hal_uart_put_char('\n');
    putstr("Hello World\n");
    Printf_test();
    Timer_test();

    while(true);
}

static void Hw_init(){
    Hal_interrupt_init();
    Hal_uart_init();
    Hal_timer_init();
}

static void Printf_test(){
    char * str = "printf pointer test";
    char* nullptr = 0;
    uint32_t i=5;
    uint32_t * sysctr10 = (uint32_t*)0x10001000;

    debug_printf("%s\n", "Hello printf");
    debug_printf("output string pointer: %s\n", "str");
    debug_printf("%s is null pointer, %u number \n", nullptr, 10);
    debug_printf("%u =5 \n", i);
    debug_printf("dec=%u hex=%x\n", 0xff, 0xff);
    debug_printf("print zero %u\n", 0);
    debug_printf("SYSCTRL0 %x\n", *sysctr10);
}

static void Timer_test(){
    while(true){
        debug_printf("current count : %u\n", Hal_timer_get_1ms_counter());
        delay(1000);
    }
}

static void Kernel_init(){
    uint32_t taskId;

    Kernel_task_init();

    taskId = Kernel_task_create(User_task0);
    if(NOT_ENOUGH_TASK_NUM == taskId){
        putstr("Task0 creation failed\n");
    }

    taskId = Kernel_task_create(User_task1);
    if(NOT_ENOUGH_TASK_NUM == taskId){
        putstr("Task1 creation failed\n");
    }
    
    taskId = Kernel_task_create(User_task2);
    if(NOT_ENOUGH_TASK_NUM == taskId){
        putstr("Task2 creation failed\n");
    }
    
}

void User_task0(){
    debug_printf("User Task #0\n");
    while(true);
}

void User_task1(){
    debug_printf("User Task #1\n");
    while(true);
}
void User_task2(){
    debug_printf("User Task #2\n");
    while(true);
}