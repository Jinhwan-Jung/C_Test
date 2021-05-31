/**
*********************************************************************************************************
*                                               CloseEye_addr Personal
*
*                                   (c) Copyright 2021 - 2041, CloseEye Study
*                                               All Rights Reserved
*   @file       TypeDef.h
*   @date       2021.05.28
*   @author     Jinhwan.Jung
*   @version    1.0
*   @brief      This file define the C type.
*   
*********************************************************************************************************
*/
#ifndef TYPEDEF_h
#define TYPEDEF_h


/*
*********************************************************************************************************
*                                           Typedef
*
*********************************************************************************************************
*/
typedef unsigned char   uint8;
typedef unsigned char   uint8_t;
typedef unsigned short  uint16;
typedef unsigned short  uint16_t;
typedef unsigned long   uint32;
typedef unsigned long   uint32_t;

typedef signed char     sint8;
typedef signed char     sint8_t;
typedef signed short    sint16;
typedef signed short    sint16_t;
typedef signed long     sint32;
typedef signed long     sint32_t;

typedef unsigned char   INT8U;
typedef unsigned short  INT16U;
typedef unsigned long   INT32U;

typedef signed char     INT8S;
typedef signed short    INT16S;
typedef signed long     INT32S;

typedef float           FP32;
typedef double          FP64;


#ifndef E_OK
#define E_OK            0u
#endif

#ifndef E_NOT_OK
#define E_NOT_OK        1u
#endif


#ifndef TRUE
#define TRUE            1u
#endif

#ifndef FALSE
#define FALSE           0u
#endif

#ifndef NULL_PTR
#define NULL_PTR        ((void *)0)
#endif


/** @def randomize() 
    - The Start point to generate a random value. @n
    - If this function is NOT called, the random value is the same always. */
#define randomize()     srand( (unsigned)time(NULL) )       


/** @def random(n) 
    - The Random value generation from 0 to n */
#define random(n)       ( rand() % (n) )


/** @def delay(n)
    - 1/1000 sec Time Delay Fucntion same as Delay_ms */
#define delay(n)        _sleep(n)


#endif  /* End of File  */

