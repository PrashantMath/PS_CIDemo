/**
  * Polyspace example.
  *       Copyright 2012-2015 The MathWorks, Inc.
  */

#include "single_file_analysis.h"
#include "single_file_private.h"
#include "include.h"

/*
   global variables declaration
   input variables for the module/function/file
*/
static u16 v0;
static s16 v1;
static s16 v2;
static u8 v3;
static s16 v4;
static s16 v5;

/* output variables for the module/function/file */
/* polyspace:begin<MISRA-C3:8.9:Not a defect:No action planned> per the comment, these variables are outputs, therefore we'll suppress the MISRA warning on the assumption that it would go away when more code is added to the project */
static s32 output_v6;
static s32 output_v7;
static s8 output_v1;

static s16 saved_values[127];
/* polyspace:end<MISRA-C3:8.9:Not a defect:No action planned> */

/* polyspace:begin<MISRA-C3:8.7:Not a defect:No action planned> volatility represents external nature */
volatile s32 tmps32;
volatile s16 tmps16;
volatile u16 tmpu16;
/* polyspace:end<MISRA-C3:8.7:Not a defect:No action planned> */


/* function definitions */

static s32 all_values_s32(s32 min, s32 max);
static s32 all_values_s32(s32 min, s32 max)
{
    s32 ret = tmps32;
    while ((ret < min) || (ret > max)) {
        ret = tmps32;
    }
    return ret;
}


static s16 all_values_s16(s16 min, s16 max);
static s16 all_values_s16(s16 min, s16 max)
{
    s16 ret = tmps16;
    while ((ret < min) || (ret > max)) {
        ret = tmps16;
    }
    return ret;
}


static u16 all_values_u16(u16 min, u16 max);
static u16 all_values_u16(u16 min, u16 max)
{
    u16 ret = tmpu16;
    assert((ret >= min) && (ret <= max));
    return ret;
}
/*
 * all_values(s32)
 * all_values(s16)
 * all_values(u16)
 */

/* Internal function         */
/* Needed for MISRA-rule 8.1 */
static s32 new_speed(s32 in, s8 ex_speed, u8 c_speed);
static u8 reset_temperature(u8 in_v3);
static void functional_ranges(void);


static void functional_ranges(void)
{
    /*  sets all global variables to their functional range */
    v0 = all_values_u16((u8)0 * (u8)BIN_v0, (u8)65535);
    /* Note : red when -detect-unsigned-overflow is being used. */

    v1 = all_values_s16(0 * BIN_v1,   90 * BIN_v1);
    v2 = all_values_s16(-810 * BIN_v2,  150 * BIN_v2);
    v3 = (u8)all_values_s32(0 * BIN_v3,   54 * BIN_v3);
    v4 = all_values_s16(-45 * BIN_v4,  126 * BIN_v4);

    v5 = all_values_s16(-90 * BIN_v5,  900 * BIN_v5);
}


static s32 new_speed(s32 in, s8 ex_speed, u8 c_speed)
{
    return ((in / 9) + (s32)ex_speed + (((s32)c_speed) / 2));
}


static u8 reset_temperature(u8 in_v3)
{
    s16 an_array[255-(54 * BIN_v3)];

    return (u8)(an_array[in_v3-(u8)255] = 0);
}


s8 generic_validation(s8 extrapolated_speed, u8 computed_speed)
{
    /**************************************************************
     * Input parameters                                           *
     *           NAME                      POSSIBLE VALUES        *
     *      s8 extrapolated_speed              [ -128 ; 127 ]     *
     *      u8 computed_speed                  [    0 ; 255 ]     *
     **************************************************************
     * Output values                                              *
     *           NAME                      POSSIBLE VALUES        *
     *      s8 ret               NA_VALUE (-128), or [ -46; 126 ] *
     **************************************************************/
    s32 s32_ret;
    s16 v0_c;
    s8 s8_ret;
    s8 answer;

    /*  sets all global variables to their functional range */
    functional_ranges();

    v0_c = (s16) v0 / 1024;
    /* unreachable, so remove
     * if (v0_c == 90)
      {
        answer = (s8) NA_VALUE;
        / * grey explanation
         * when initialized, v0 is truncated to [ 0 ; 26624]
         * instead of [ 0 ; 92160 ] (92160 = 90 * BIN_v0)
         *
         * Note:
         *        90 * BIN_v0 = 90 * 1024 = 92160
         *        and  92160 MOD [ 0 ; 65535] = 26624
         * to detect this bug earlier, use the
         * -detect-unsigned-overflow option.
         *
      }
    else */
    {

        if (v1 >= (60 * BIN_v1)) {
            output_v6 = (s32)((((s32)v2 / 32) * ((s32)v4 / 8)) / ((s32)v1 / 256));
        } else {
            output_v6 = (s32)((((s32)v3 / 4) * ((s32)v1 / 256)) - ((s32)v5 / 16));
        }
        output_v7 = new_speed(output_v6, extrapolated_speed, computed_speed);
        s32_ret = new_speed(output_v7, extrapolated_speed, computed_speed) / 2;


        s8_ret = (s8) NA_VALUE;
        /* the return value spec indicates that it should be between [ -50 ; 126 ] */
        if ((s32_ret < -50) || (s32_ret >  126)) {
            /* if dead code, we can remove this test
             *   - gain in execution speed
             *   - gain for the other developers who don't need to test the return
             *     value against NA_VALUE (-128)
             */
            SEND_MESSAGE(s32_ret, "%d out of functional bounds reached");
        } else {
            if (s32_ret >= 0) {
                s8_ret = (s8) s32_ret;
                output_v1 = (s8)((s16)s8_ret + 15);
            }
        }

        if ((output_v7 >= 0) && (output_v7 <= 126)) {
            saved_values[output_v7] = (s16)s8_ret;
            answer = s8_ret;
        } else {
            answer = (s8)reset_temperature(v3);
        }
    }
    return answer;
}


static s32 unused_fonction(void);
static s32 unused_fonction(void)
{
    /* polyspace<MISRA-C3:10.3:Low:Improve> Danger of implicit casting is mitigated by use of code verification to detect overflow and underflow possibilities, but explicit casts are better form */
    return saved_values[output_v1] + (s32) generic_validation((output_v6 / 10000) , (output_v7 / 16000));
}
