/**
*********************************************************************************************************
*                                               CloseEye_addr Personal
* 
*                                   (c) Copyright 2021 - 2041, CloseEye Study
*                                               All Rights Reserved
*   @file       Console_Dbg.c
*   @date       2021.05.28
*   @author     Jinhwan.Jung
*   @version    1.0
*   @brief      
*               
*   
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


//#include "CanIfCdd_Includes.h"
//#include "DcmCdd_Includes.h"
//#include "Diag_Includes.h"





/*
*********************************************************************************************************
*                                           Macro Define
*
*********************************************************************************************************
*/
#define DBG_CMD_LINE_MAX               16
#define MAX_ARGS                        8



/*
*********************************************************************************************************
*                                           Local Variable
*
*********************************************************************************************************
*/
static char Dbg_Cmd_Exit = FALSE;

static char Dbg_Cmd_Line[DBG_CMD_LINE_MAX] = { "cmd" };



/*
*********************************************************************************************************
*                                           Local Function Prototype
*
*********************************************************************************************************
*/
static void Dbg_Get_Str (char *pBuf);
static void Dbg_Cmd_Proc(char *pBuf);

static int  cmd_Help (int argc, char *argv[]);
static int  cmd_CanTx(int argc, char *argv[]);
static int  cmd_Exit (int argc, char *argv[]);



/*
*********************************************************************************************************
*                                           Command Table0
*
*********************************************************************************************************
*/
const char  *msg_Help[] = {
            "HELP",
            (char *)0
};

const char  *msg_Exit[] = {
            "Test Termination",
            (char *)0
};



Cmd_Table_st    Cmd_Table[] = {
    {"?",           cmd_Help,               msg_Help   },
    {"h",           cmd_Help,               msg_Help   },
    {"help",        cmd_Help,               msg_Help   },
    {"cantx",       cmd_CanTx,              msg_Help   },

    {"t",           cmd_Test,               msg_Help   },    

    {"secu",        cmd_Secu,               msg_Help   },        

    {"exit",        cmd_Exit,               msg_Exit   },
    { NULL,         NULL,                   NULL       }

};
    

/**
*********************************************************************************************************
*   @fn                         void Console_Dbg_Task(uint8 *pExitVar)
*   @author         Jinhwan.Jung
*   @param          pExitVar - If this variable is set with TURE, the Main function is terminated.
*   @return         default (0)
*   @remark         For the Debugging function in the Console  @n
*                   This function should be called every 5ms in a [5ms Task].
*********************************************************************************************************
*/
void Console_Dbg_Task(uint8 *pExitVar)
{
    char    cmd[50] = {0};

    Dbg_Get_Str ( cmd );
    Dbg_Cmd_Proc( cmd );        

    *pExitVar = Dbg_Cmd_Exit;
}


/**
*********************************************************************************************************
*   @fn                         static void Dbg_Get_Str(char *pBuf)
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         It is received the command string from the console.
*********************************************************************************************************
*/
static void Dbg_Get_Str(char *pBuf)
{
    static uint8    newStart = TRUE;

    if (newStart == TRUE)
    {
        newStart = FALSE;
        printf("%s>", Dbg_Cmd_Line);
    }

    if ( _kbhit() )
    {
        gets_s(pBuf, 50u);
        newStart = TRUE;
    }
}


/**
*********************************************************************************************************
*   @fn                         static void Dbg_Cmd_Proc(char *pBuf)
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         It is received the command string from the console.
*********************************************************************************************************
*/
static void Dbg_Cmd_Proc(char *pBuf)
{
    uint8           match = FALSE;
    static char    *argv[10];
    char           *pcChar;
    int             argc;
    int             bFindArg = 1;
    Cmd_Table_st   *pCmdEntry;
   

    argc   = 0;
    pcChar = pBuf;

    while(*pcChar)
    {
        if (*pcChar == ' ')
        {
           *pcChar   = 0u;
            bFindArg = 1u;
        }
        else
        {
            if (bFindArg)
            {
                if (argc < MAX_ARGS)
                {
                    argv[argc] = pcChar;
                    argc++;
                    bFindArg   = 0;
                }
            }
        }
        pcChar++;
    }

    if (argc)
    {
         pCmdEntry = Cmd_Table;

         while(pCmdEntry->pCmd)
         {
             if( !strcmp( argv[0], (char *)pCmdEntry->pCmd) )
             {
                pCmdEntry->pFuncCmd(argc, argv);
                match = TRUE;
                break;
             }

             pCmdEntry++;
         }

        if (match == FALSE)
        {
             printf(" Bad or Not Cmd\n");
        }
    }
}




/**
*********************************************************************************************************
*   @fn                         static int cmd_Help(int argc, char *argv[])
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         It is received the command string from the console.
*********************************************************************************************************
*/
static int cmd_Help(int argc, char *argv[])
{
    uint8   i = 0u;
    
    printf("\n *************************************");
    printf("\n *    Command List for Debuging      *");
    printf("\n *-----------------------------------*");    

    while(Cmd_Table[i].pCmd != NULL)
    {
        printf("\n * %10s  %20s  *", Cmd_Table[i].pCmd, *Cmd_Table[i].pHelp);
        i++;
    }
    printf("\n *************************************\n");    

    return 0;
}


/**
*********************************************************************************************************
*   @fn                         static int cmd_CanTx(int argc, char *argv[])
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         It is received the command string from the console.
*********************************************************************************************************
*/

static int cmd_CanTx(int argc, char *argv[])
{
    printf("\n Can Tx");

    printf("\n");
    return 0;
}


/**
*********************************************************************************************************
*   @fn                         static int cmd_Exit(int argc, char *argv[])
*   @author         Jinhwan.Jung
*   @return         default (0)
*   @remark         It is received the command string from the console.
*********************************************************************************************************
*/

static int cmd_Exit(int argc, char *argv[])
{
    Dbg_Cmd_Exit = TRUE;
    return 0;
}

