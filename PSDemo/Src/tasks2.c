/**
  * Polyspace example.
  *       Copyright 2012-2015 The MathWorks, Inc.
  */

#include "include.h"


/* Internal function         */
/* Needed for MISRA-rule 8.1 */
/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Computing_from_Sensors(int i, int j);
/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Command_Ordering(int X);
/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Pilot_Balance(int X);
/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Sequencer(int X);


void Increase_PowerLevel(void)
{
    PowerLevel++;
}


/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Computing_from_Sensors(int i, int j)
{
    /* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
    int loc = i + j;
    /* polyspace<MISRA-C3:15.6:Low:Improve> Easy to see that there is no else, but worth changing for homogeneity and for ease of rule checker */
    if (loc < 0) loc++;
}


void Compute_Injection(void)
{
    /* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
    static int Injection;

    Computing_from_Sensors(PowerLevel, Injection);
}


/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
int Get_PowerLevel(void)
{
    /* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
    int Tmp;
    Tmp = PowerLevel;
    return Tmp;
}


/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Command_Ordering(int X)
{
    /* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
    volatile int loc = 0;
    X = loc;
    /* polyspace<MISRA-C3:15.6:Low:Improve> Easy to see that there is no else, but worth changing for homogeneity and for ease of rule checker */
    if (X == 12) loc = orderregulate();
}


/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Pilot_Balance(int X)
{
    Command_Ordering(X);
}


/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
static void Sequencer(int X)
{
    Command_Ordering(X);
}


/* polyspace<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace builtin types */
void Exec_One_Cycle(int X)
{
    Pilot_Balance(X);
    Sequencer(X);
}


/* Critical sections */
void Begin_CS(void)
{
}


void End_CS(void)
{
}
