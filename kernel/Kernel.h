#ifndef KERNEL_KERNEL_H_
#define KERNEL_KERNEL_H_

#include "task.h"
#include "event.h"

void Kernel_start();
void Kernel_yield();
void Kernel_send_events(uint32_t event_list);
KernelEventFlag_t Kernel_wait_events(uint32_t waiting_list);
#endif