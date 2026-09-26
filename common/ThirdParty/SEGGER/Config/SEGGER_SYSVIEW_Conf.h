/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************
*            (c) 1995 - 2024 SEGGER Microcontroller GmbH             *
*       www.segger.com     Support: support@segger.com               *
**********************************************************************
*       SEGGER SystemView * Real-time application analysis           *
**********************************************************************
* Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following
* condition is met:
* o Redistributions of source code must retain the above copyright
*   notice, this condition and the following disclaimer.
*
* THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND.
**********************************************************************
-------------------------- END-OF-HEADER -----------------------------

File    : SEGGER_SYSVIEW_Conf.h
Purpose : SEGGER SystemView configuration file.
          Set defines which deviate from the defaults (see SEGGER_SYSVIEW_ConfDefaults.h) here.          
Revision: $Rev: 21292 $

Additional information:
  Required defines which must be set are:
    SEGGER_SYSVIEW_GET_TIMESTAMP
    SEGGER_SYSVIEW_GET_INTERRUPT_ID
  For known compilers and cores, these might be set to good defaults
  in SEGGER_SYSVIEW_ConfDefaults.h.
  
  SystemView needs a (nestable) locking mechanism.
  If not defined, the RTT locking mechanism is used,
  which then needs to be properly configured.
*/

#ifndef SEGGER_SYSVIEW_CONF_H
#define SEGGER_SYSVIEW_CONF_H

/*********************************************************************
*
*       Defines, configurable
*
**********************************************************************
*/

/*********************************************************************
*       Define: SEGGER_SYSVIEW_SECTION
*
*  Description
*    Section to place the SystemView RTT Buffer into.
*  Default
*    undefined: Do not place into a specific section.
*  Notes
*    If SEGGER_RTT_SECTION is defined, the default changes to use
*    this section for the SystemView RTT Buffer, too.
*/

#if !(defined SEGGER_SYSVIEW_SECTION) && (defined SEGGER_RTT_BUFFER_SECTION)
  #define SEGGER_SYSVIEW_SECTION SEGGER_RTT_BUFFER_SECTION
#endif

/*********************************************************************
* TODO: Add your defines here.
**********************************************************************
*/

// SystemView is transported through the J-Link RTT channel in this project.
#define SEGGER_UART_REC 0
#define SEGGER_SYSVIEW_RTT_CHANNEL 1

#if (SEGGER_UART_REC == 1)
extern void HIF_UART_EnableTXEInterrupt(void);
#define SEGGER_SYSVIEW_ON_EVENT_RECORDED(x) HIF_UART_EnableTXEInterrupt()
#endif

#endif  // SEGGER_SYSVIEW_CONF_H

/*************************** End of file ****************************/
