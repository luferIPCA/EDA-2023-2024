/**

    @file      Queue.h
    @brief     Assinatura das funções que gerem a Queue
    @details   ~
    @author    lufer
    @date      1.05.2024
    @copyright © lufer - IPCA 2024. All right reserved.

**/
#pragma once

// Queue signature functions 

bool insertQueue(int queue[], int* rear, int data);
int removeQueue(int queue[], int* front);
bool isQueueEmpty(int rear, int front);
