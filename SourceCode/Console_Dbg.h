/**
*********************************************************************************************************
*                                               CloseEye_addr Personal
* 
*                                   (c) Copyright 2021 - 2041, CloseEye Study
*                                               All Rights Reserved
*   @file       Console_Dbg.h
*   @date       2021.05.28
*   @author     Jinhwan.Jung
*   @version    1.0
*   @brief      
*               
*   
*********************************************************************************************************
*/
#ifndef CONSOLE_DBG_h
#define CONSOLE_DBG_h


/*
*********************************************************************************************************
*                                           Typedefine
*
*********************************************************************************************************
*/
typedef int (*pFuncCmd)(int argc, char *argv[]);


typedef struct {
    const char   *pCmd;

    pFuncCmd      pFuncCmd;

    const char  **pHelp;

}Cmd_Table_st;



/*
*********************************************************************************************************
*                                           Function Prototype
*
*********************************************************************************************************
*/
extern void Console_Dbg_Task(uint8 *pExitVar);




#endif  /* End of File  */


