/**
  * Polyspace example.
  *       Copyright 2012-2015 The MathWorks, Inc.
  */

#include "include.h"

/* polyspace:begin<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace inbuilt types */
static int* current_data;

/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the variable is used outside this file so it should probably be static (and the spelling could do with fixing) */
int tab[MAX_SIZE];
int* arr = tab;

/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the variable is used outside this file so it should probably be static (and the spelling could do with fixing) */
int first_payload = 100;
/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the variable is used outside this file so it should probably be static (and the spelling could do with fixing) */
int second_payload = 200;

/* Internal function         */
/* Needed for MISRA-rule 8.1 */
/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the function is used outside this file so it should probably be static */
int return_code(int y);
/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the function is used outside this file so it should probably be static */
int degree_computation(int a, int b, int c, int x);


void initialise_current_data(void)
{
    int i;

    current_data = &first_payload;
    for (i = 0; i < MAX_SIZE; i++) {
        tab[i] = 12;
    }
}


/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the function is used outside this file so it should probably be static */
void partial_init(int* new_alt)
{

    /* polyspace<MISRA-C3:14.4:High:Fix> treating 0 or non-0 as special and expecting knowledge of all function return values is unacceptable  */
    if (read_bus_status()) {
        *new_alt = true;
    }
}


void compute_new_coordonates(void)
{
    int new_altitude;

    partial_init(&new_altitude);
    if (new_altitude == true) {
        *current_data = 100;
    } else {
        *current_data = 100;
    }
}


/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the function is used outside this file so it should probably be static */
int return_code(int y)
{
    return (2 * y);
}


/* polyspace<MISRA-C3:15.5:Low:Improve> Implement the rule for its own sake here */
/* polyspace<MISRA-C3:8.7:Low:Improve> Doesn't look like the function is used outside this file so it should probably be static */
int degree_computation(int a, int b, int c, int x)
{
    int y;
    /* polyspace<MISRA-C3:12.1:Low:Improve> The order is unlikely to be wrong but being explicit (adding brackets) would be safer */
    y = a * x * x + b * x + c;

    if ((y < -93) || (y > 63)) {
        return return_code(y);
    } else {
        /* polyspace<MISRA-C3:12.1:Low:Improve> The order is unlikely to be wrong but being explicit (adding brackets) would be safer */
        return 2 * x + 1;
    }
}


/* polyspace<MISRA-C3:15.5:Medium:Improve> Not only does removing the extra return make the code safer and more maintainable but it also simplifies and reduces the instruction */
int polynomia(int input)
{
    int y, i;

    for (i = 0; i <= input; i++) {
        y = degree_computation(1, -23, -15, i);
    }

    if ((y >= -5) && (y <= 7)) {
        return y;
    } else {
        y = return_code(10);
        return y;
    }
}


/* polyspace:end<MISRA-C3:D4.6:Medium:Fix> Add a types.h file, create typedefs and replace inbuilt types */
