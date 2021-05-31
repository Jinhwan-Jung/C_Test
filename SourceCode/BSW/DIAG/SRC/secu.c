/**
*********************************************************************************************************
*                                               CloseEye_addr Personal
* 
*                                   (c) Copyright 2021 - 2041, CloseEye Study
*                                               All Rights Reserved
*   @file       test_Prgm.c
*   @date       2021.05.31
*   @author     Jinhwan.Jung
*   @version    1.0
*   @brief      This file starts at first when the program is run. @n
*               This file was created for testing with the C compiler(MS Visual Studio). @n
*               The purpose of this project is to implement the UDS without and Embeded system. @n
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           Include Files
*
*********************************************************************************************************
*/
#include "Cmn_Includes.h"
#include "Test_Includes.h"


/*
*********************************************************************************************************
*                                           Global Variable
*
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local Function Prototype
*
*********************************************************************************************************
*/


/**
*********************************************************************************************************
*   @fn                         int  cmd_Secu(int argc, char *argv[])
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         StartUp Main Function @n
*********************************************************************************************************
*/
int  cmd_Secu(int argc, char *argv[])
{
    char    cmd = *argv[1];

    switch (cmd)
    {
    case '1'    :   printf("\n Security HKMC");     break;
    case '2'    :   printf("\n Security SYMC");     break;
    case '3'    :   printf("\n Security CEVT");     break;

    default     :   printf("\n Bad or Not cmd");    break;


    }

    printf("\n ");

    return 0;
}

