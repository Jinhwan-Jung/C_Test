/**
*********************************************************************************************************
*                                               CloseEye_addr Personal
* 
*                                   (c) Copyright 2021 - 2041, CloseEye Study
*                                               All Rights Reserved
*   @file       main.c
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

#include "main.h"


/*
*********************************************************************************************************
*                                           Global Variable
*
*********************************************************************************************************
*/
uint8   ExitMain = FALSE;


/*
*********************************************************************************************************
*                                           Local Function Prototype
*
*********************************************************************************************************
*/
static void Main_StartUp_Disp(void);


/**
*********************************************************************************************************
*   @fn                         int main(void)
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         StartUp Main Function @n
*                   This function can be replaced with the entry point function for the Embedded System.
*********************************************************************************************************
*/
int main(int argc, char *argv[])
{
    Main_StartUp_Disp();

    while(1)
    {
        if ( clock() % 5u == 0u)                                                /* 5ms Task Polling     */
        {
            Console_Dbg_Task( &ExitMain );
            
            if (ExitMain == TRUE)
                break;        
        }
    }
    return 0;
}



/**
*********************************************************************************************************
*   @fn                         int main(void)
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         StartUp Main Function @n
*                   This function can be replaced with the entry point function for the Embedded System.
*********************************************************************************************************
*/
static void Main_StartUp_Disp(void)
{
    printf("\n**********************************************");
    printf("\n*  C languate test for My Job                *");
    printf("\n**********************************************");
    printf("\n - Firmware Version  : %s", FW_VERSION );
    printf("\n - Hardware Version  : %s", HW_VERSION );    
    printf("\n - Author   Name     : %s", AUTHOR_NAME);    

    printf("\n - Compiled Date     : %s-%s", __DATE__, __TIME__);
    printf("\n**********************************************\n");
}


