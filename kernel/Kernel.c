#include "stdint.h"
#include "stdboo.h"

#include "Kernel.h"

void Kernel_yield(){
    Kernel_task_scheduler();
}