/*
 *  This file is written using examples provided by Spectrum Digital --> sine_sq_Tr_17Aug18
 */


#include "stdio.h"
#include "string.h"
#include "usbstk5515.h"
#include "usbstk5515_gpio.h"
#include "usbstk5515_i2c.h"
#include "sar.h"
#include"lcd.h"
#define OSD9616_I2C_ADDR 0x3C // OSD9616 I2C address


#define AIC3204_I2C_ADDR 0x18
#define Rcv 0x08
#define Xmit 0x20

#ifndef TRUE
#define TRUE 1
#endif

int N_sample = 1536*2;
int N_table = 384*2;
#define freq_6_857 0xF1
#define freq_8 0xE1
#define freq_9_6 0xD1
#define freq_12 0xC1
#define freq_16 0xB1
#define freq_24 0xA1
#define freq_48 0x91

unsigned char sample_skip[10] ={1, 8,16,24,32,40, 48, 56,64 ,96 };
    unsigned char i = 0;
    unsigned char j = 0;/*

*/
Int16 sinetable[768] ={
                        0,
                        67,
                        134,
                        201,
                        268,
                        335,
                        402,
                        469,
                        536,
                        603,
                        670,
                        737,
                        804,
                        871,
                        938,
                        1005,
                        1072,
                        1139,
                        1206,
                        1273,
                        1339,
                        1406,
                        1473,
                        1540,
                        1607,
                        1674,
                        1741,
                        1808,
                        1875,
                        1942,
                        2009,
                        2076,
                        2143,
                        2209,
                        2276,
                        2343,
                        2410,
                        2477,
                        2544,
                        2610,
                        2677,
                        2744,
                        2811,
                        2878,
                        2944,
                        3011,
                        3078,
                        3145,
                        3211,
                        3278,
                        3345,
                        3411,
                        3478,
                        3545,
                        3611,
                        3678,
                        3744,
                        3811,
                        3877,
                        3944,
                        4011,
                        4077,
                        4144,
                        4210,
                        4276,
                        4343,
                        4409,
                        4476,
                        4542,
                        4608,
                        4675,
                        4741,
                        4807,
                        4874,
                        4940,
                        5006,
                        5072,
                        5139,
                        5205,
                        5271,
                        5337,
                        5403,
                        5469,
                        5535,
                        5601,
                        5667,
                        5733,
                        5799,
                        5865,
                        5931,
                        5997,
                        6063,
                        6129,
                        6195,
                        6261,
                        6326,
                        6392,
                        6458,
                        6523,
                        6589,
                        6655,
                        6720,
                        6786,
                        6851,
                        6917,
                        6982,
                        7048,
                        7113,
                        7179,
                        7244,
                        7310,
                        7375,
                        7440,
                        7505,
                        7571,
                        7636,
                        7701,
                        7766,
                        7831,
                        7896,
                        7961,
                        8026,
                        8091,
                        8156,
                        8221,
                        8286,
                        8351,
                        8415,
                        8480,
                        8545,
                        8610,
                        8674,
                        8739,
                        8803,
                        8868,
                        8932,
                        8997,
                        9061,
                        9126,
                        9190,
                        9254,
                        9319,
                        9383,
                        9447,
                        9511,
                        9575,
                        9639,
                        9703,
                        9767,
                        9831,
                        9895,
                        9959,
                        10023,
                        10087,
                        10151,
                        10214,
                        10278,
                        10342,
                        10405,
                        10469,
                        10532,
                        10596,
                        10659,
                        10722,
                        10786,
                        10849,
                        10912,
                        10975,
                        11038,
                        11101,
                        11164,
                        11227,
                        11290,
                        11353,
                        11416,
                        11479,
                        11542,
                        11604,
                        11667,
                        11730,
                        11792,
                        11855,
                        11917,
                        11980,
                        12042,
                        12104,
                        12166,
                        12229,
                        12291,
                        12353,
                        12415,
                        12477,
                        12539,
                        12601,
                        12663,
                        12724,
                        12786,
                        12848,
                        12909,
                        12971,
                        13033,
                        13094,
                        13155,
                        13217,
                        13278,
                        13339,
                        13400,
                        13462,
                        13523,
                        13584,
                        13645,
                        13706,
                        13766,
                        13827,
                        13888,
                        13949,
                        14009,
                        14070,
                        14130,
                        14191,
                        14251,
                        14311,
                        14372,
                        14432,
                        14492,
                        14552,
                        14612,
                        14672,
                        14732,
                        14792,
                        14852,
                        14911,
                        14971,
                        15030,
                        15090,
                        15149,
                        15209,
                        15268,
                        15327,
                        15387,
                        15446,
                        15505,
                        15564,
                        15623,
                        15682,
                        15740,
                        15799,
                        15858,
                        15917,
                        15975,
                        16034,
                        16092,
                        16150,
                        16209,
                        16267,
                        16325,
                        16383,
                        16441,
                        16499,
                        16557,
                        16615,
                        16672,
                        16730,
                        16788,
                        16845,
                        16903,
                        16960,
                        17017,
                        17074,
                        17132,
                        17189,
                        17246,
                        17303,
                        17360,
                        17416,
                        17473,
                        17530,
                        17586,
                        17643,
                        17699,
                        17756,
                        17812,
                        17868,
                        17924,
                        17980,
                        18036,
                        18092,
                        18148,
                        18204,
                        18260,
                        18315,
                        18371,
                        18426,
                        18482,
                        18537,
                        18592,
                        18647,
                        18702,
                        18757,
                        18812,
                        18867,
                        18922,
                        18976,
                        19031,
                        19086,
                        19140,
                        19194,
                        19249,
                        19303,
                        19357,
                        19411,
                        19465,
                        19519,
                        19573,
                        19626,
                        19680,
                        19733,
                        19787,
                        19840,
                        19894,
                        19947,
                        20000,
                        20053,
                        20106,
                        20159,
                        20212,
                        20264,
                        20317,
                        20369,
                        20422,
                        20474,
                        20527,
                        20579,
                        20631,
                        20683,
                        20735,
                        20787,
                        20838,
                        20890,
                        20942,
                        20993,
                        21045,
                        21096,
                        21147,
                        21198,
                        21249,
                        21300,
                        21351,
                        21402,
                        21453,
                        21503,
                        21554,
                        21604,
                        21655,
                        21705,
                        21755,
                        21805,
                        21855,
                        21905,
                        21955,
                        22004,
                        22054,
                        22104,
                        22153,
                        22202,
                        22252,
                        22301,
                        22350,
                        22399,
                        22448,
                        22496,
                        22545,
                        22594,
                        22642,
                        22691,
                        22739,
                        22787,
                        22835,
                        22883,
                        22931,
                        22979,
                        23027,
                        23074,
                        23122,
                        23169,
                        23217,
                        23264,
                        23311,
                        23358,
                        23405,
                        23452,
                        23499,
                        23545,
                        23592,
                        23638,
                        23685,
                        23731,
                        23777,
                        23823,
                        23869,
                        23915,
                        23961,
                        24006,
                        24052,
                        24097,
                        24143,
                        24188,
                        24233,
                        24278,
                        24323,
                        24368,
                        24413,
                        24457,
                        24502,
                        24546,
                        24591,
                        24635,
                        24679,
                        24723,
                        24767,
                        24811,
                        24855,
                        24898,
                        24942,
                        24985,
                        25029,
                        25072,
                        25115,
                        25158,
                        25201,
                        25243,
                        25286,
                        25329,
                        25371,
                        25414,
                        25456,
                        25498,
                        25540,
                        25582,
                        25624,
                        25665,
                        25707,
                        25749,
                        25790,
                        25831,
                        25872,
                        25913,
                        25954,
                        25995,
                        26036,
                        26077,
                        26117,
                        26158,
                        26198,
                        26238,
                        26278,
                        26318,
                        26358,
                        26398,
                        26437,
                        26477,
                        26516,
                        26556,
                        26595,
                        26634,
                        26673,
                        26712,
                        26751,
                        26789,
                        26828,
                        26866,
                        26905,
                        26943,
                        26981,
                        27019,
                        27057,
                        27094,
                        27132,
                        27170,
                        27207,
                        27244,
                        27281,
                        27319,
                        27355,
                        27392,
                        27429,
                        27466,
                        27502,
                        27538,
                        27575,
                        27611,
                        27647,
                        27683,
                        27719,
                        27754,
                        27790,
                        27825,
                        27861,
                        27896,
                        27931,
                        27966,
                        28001,
                        28036,
                        28070,
                        28105,
                        28139,
                        28173,
                        28208,
                        28242,
                        28275,
                        28309,
                        28343,
                        28377,
                        28410,
                        28443,
                        28477,
                        28510,
                        28543,
                        28575,
                        28608,
                        28641,
                        28673,
                        28706,
                        28738,
                        28770,
                        28802,
                        28834,
                        28866,
                        28897,
                        28929,
                        28960,
                        28992,
                        29023,
                        29054,
                        29085,
                        29116,
                        29146,
                        29177,
                        29207,
                        29238,
                        29268,
                        29298,
                        29328,
                        29358,
                        29387,
                        29417,
                        29446,
                        29476,
                        29505,
                        29534,
                        29563,
                        29592,
                        29621,
                        29649,
                        29678,
                        29706,
                        29734,
                        29762,
                        29790,
                        29818,
                        29846,
                        29873,
                        29901,
                        29928,
                        29955,
                        29983,
                        30009,
                        30036,
                        30063,
                        30090,
                        30116,
                        30142,
                        30169,
                        30195,
                        30221,
                        30247,
                        30272,
                        30298,
                        30323,
                        30349,
                        30374,
                        30399,
                        30424,
                        30449,
                        30473,
                        30498,
                        30522,
                        30547,
                        30571,
                        30595,
                        30619,
                        30643,
                        30666,
                        30690,
                        30713,
                        30737,
                        30760,
                        30783,
                        30806,
                        30828,
                        30851,
                        30874,
                        30896,
                        30918,
                        30940,
                        30962,
                        30984,
                        31006,
                        31028,
                        31049,
                        31070,
                        31092,
                        31113,
                        31134,
                        31154,
                        31175,
                        31196,
                        31216,
                        31236,
                        31257,
                        31277,
                        31297,
                        31316,
                        31336,
                        31356,
                        31375,
                        31394,
                        31413,
                        31432,
                        31451,
                        31470,
                        31489,
                        31507,
                        31525,
                        31544,
                        31562,
                        31580,
                        31597,
                        31615,
                        31633,
                        31650,
                        31667,
                        31684,
                        31701,
                        31718,
                        31735,
                        31752,
                        31768,
                        31785,
                        31801,
                        31817,
                        31833,
                        31849,
                        31864,
                        31880,
                        31895,
                        31911,
                        31926,
                        31941,
                        31956,
                        31970,
                        31985,
                        31999,
                        32014,
                        32028,
                        32042,
                        32056,
                        32070,
                        32084,
                        32097,
                        32110,
                        32124,
                        32137,
                        32150,
                        32163,
                        32176,
                        32188,
                        32201,
                        32213,
                        32225,
                        32237,
                        32249,
                        32261,
                        32273,
                        32284,
                        32295,
                        32307,
                        32318,
                        32329,
                        32340,
                        32350,
                        32361,
                        32371,
                        32382,
                        32392,
                        32402,
                        32412,
                        32422,
                        32431,
                        32441,
                        32450,
                        32459,
                        32468,
                        32477,
                        32486,
                        32495,
                        32503,
                        32512,
                        32520,
                        32528,
                        32536,
                        32544,
                        32552,
                        32559,
                        32567,
                        32574,
                        32581,
                        32588,
                        32595,
                        32602,
                        32609,
                        32615,
                        32622,
                        32628,
                        32634,
                        32640,
                        32646,
                        32651,
                        32657,
                        32662,
                        32668,
                        32673,
                        32678,
                        32683,
                        32687,
                        32692,
                        32696,
                        32701,
                        32705,
                        32709,
                        32713,
                        32717,
                        32720,
                        32724,
                        32727,
                        32730,
                        32733,
                        32736,
                        32739,
                        32742,
                        32744,
                        32747,
                        32749,
                        32751,
                        32753,
                        32755,
                        32757,
                        32758,
                        32760,
                        32761,
                        32762,
                        32763,
                        32764,
                        32765,
                        32765,
                        32766,
                        32766,
                        32766
};
Int16 OSD9616_send( Uint16 comdat, Uint16 data )
{
 Uint8 cmd[2];
 cmd[0] = comdat & 0x00FF; // Specifies whether data is Command or Data
 cmd[1] = data; // Command / Data
 return USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
}

Int16 printLetter(Uint16 l1,Uint16 l2,Uint16 l3,Uint16 l4)
{
OSD9616_send(0x40,l4);
 OSD9616_send(0x40,l3);
 OSD9616_send(0x40,l2);
 OSD9616_send(0x40,l1);
 OSD9616_send(0x40,0x00);
 return 0;
}



//Int16 sinetable[48] = {
//       0x0000, 0x10b4, 0x2120, 0x30fb, 0x3fff, 0x4dea, 0x5a81, 0x658b,
//       0x6ed8, 0x763f, 0x7ba1, 0x7ee5, 0x7ffd, 0x7ee5, 0x7ba1, 0x76ef,
//       0x6ed8, 0x658b, 0x5a81, 0x4dea, 0x3fff, 0x30fb, 0x2120, 0x10b4,
//       0x0000, 0xef4c, 0xdee0, 0xcf06, 0xc002, 0xb216, 0xa57f, 0x9a75,
//       0x9128, 0x89c1, 0x845f, 0x811b, 0x8002, 0x811b, 0x845f, 0x89c1,
//       0x9128, 0x9a76, 0xa57f, 0xb216, 0xc002, 0xcf06, 0xdee0, 0xef4c
//   };
//Int16 sinetable[48]={4277,    8481,   12540,  16384,  19948,  23170,  25997,  28378,  30274,  31651,  32488,  32767,  32488,  31651,  30274,  28378,  25997,  23170,  19948,  16384,  12540,  8481,   4277,   0,  -4277,  -8481,  -12540, -16384, -19948, -23170, -25997, -28378, -30274, -31651, -32488, -32768, -32488, -31651, -30274, -28378, -25997, -23170, -19948, -16384, -12540, -8481,  -4277,  0};
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Testing Function                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 AIC3204_rget(  Uint16 regnum, Uint16* regval )
{
    Int16 retcode = 0;
    Uint8 cmd[2];

    cmd[0] = regnum & 0x007F;       // 7-bit Register Address
    cmd[1] = 0;

    retcode |= USBSTK5515_I2C_write( AIC3204_I2C_ADDR, cmd, 1 );
    retcode |= USBSTK5515_I2C_read( AIC3204_I2C_ADDR, cmd, 1 );

    *regval = cmd[0];
    USBSTK5515_wait( 10 );
    return retcode;
}

Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )
{
    Uint8 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Register Address
    cmd[1] = regval;                // 8-bit Register Data

    return USBSTK5515_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );
}

void AIC3204_config(Uint8 sampling_freq)
{
    /* Configure AIC3204 */
     AIC3204_rset( 0, 0 );          // Select page 0
    AIC3204_rset( 1, 1 );          // Reset codec
    AIC3204_rset( 0, 1 );          // Select page 1
    AIC3204_rset( 1, 8 );          // Disable crude AVDD generation from DVDD
    AIC3204_rset( 2, 1 );          // Enable Analog Blocks, use LDO power
    AIC3204_rset( 0, 0 );          // Select page 0
    /* PLL and Clocks config and Power Up  */
    AIC3204_rset( 27, 0x0d );      // BCLK and WCLK is set as o/p to AIC3204(Master)
    AIC3204_rset( 28, 0x00 );      // Data ofset = 0
    AIC3204_rset( 4, 3 );          // PLL setting: PLLCLK <- MCLK, CODEC_CLKIN <-PLL CLK
    AIC3204_rset( 6, 7 );          // PLL setting: J=7
    AIC3204_rset( 7, 0x06 );       // PLL setting: HI_BYTE(D=1680)
    AIC3204_rset( 8, 0x90 );       // PLL setting: LO_BYTE(D=1680)
    AIC3204_rset( 30, 0x88 );      // For 32 bit clocks per frame in Master mode ONLY
                                   // BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs
    AIC3204_rset( 5, sampling_freq);       // PLL setting: Power up PLL, P=1 and R=1
    AIC3204_rset( 13, 0 );         // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
    AIC3204_rset( 14, 0x80 );      // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080
    AIC3204_rset( 20, 0x80 );      // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
    AIC3204_rset( 11, 0x82 );      // Power up NDAC and set NDAC value to 2
    AIC3204_rset( 12, 0x87 );      // Power up MDAC and set MDAC value to 7
    AIC3204_rset( 18, 0x87 );      // Power up NADC and set NADC value to 7
    AIC3204_rset( 19, 0x82 );      // Power up MADC and set MADC value to 2
    /* DAC ROUTING and Power Up */
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 12, 0x08 );      // LDAC AFIR routed to HPL
    AIC3204_rset( 13, 0x08 );      // RDAC AFIR routed to HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 64, 0x02 );      // Left vol=right vol
    AIC3204_rset( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right tracks Left
    AIC3204_rset( 63, 0xd4 );      // Power up left,right data paths and set channel
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 16, 0x00 );      // Unmute HPL , 0dB gain
    AIC3204_rset( 17, 0x00 );      // Unmute HPR , 0dB gain
    AIC3204_rset(  9, 0x30 );      // Power up HPL,HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    USBSTK5515_wait( 500 );        // Wait

    /* ADC ROUTING and Power Up */
    AIC3204_rset( 0, 1 );          // Select page 1
    AIC3204_rset( 0x34, 0x30 );    // STEREO 1 Jack
                                   // IN2_L to LADC_P through 40 kohm
    AIC3204_rset( 0x37, 0x30 );    // IN2_R to RADC_P through 40 kohmm
    AIC3204_rset( 0x36, 3 );       // CM_1 (common mode) to LADC_M through 40 kohm
    AIC3204_rset( 0x39, 0xc0 );    // CM_1 (common mode) to RADC_M through 40 kohm
    AIC3204_rset( 0x3b, 0 );       // MIC_PGA_L unmute
    AIC3204_rset( 0x3c, 0 );       // MIC_PGA_R unmute
    AIC3204_rset( 0, 0 );          // Select page 0
    AIC3204_rset( 0x51, 0xc0 );    // Powerup Left and Right ADC
    AIC3204_rset( 0x52, 0 );       // Unmute Left and Right ADC
    AIC3204_rset( 0,44 );   // B Left filter coefficients
    AIC3204_rset( 44, 0x13);
    AIC3204_rset(45, 0xaf);
    AIC3204_rset(46, 0x26);
    AIC3204_rset(48, 0xe7);
    AIC3204_rset(49, 0xe4);
    AIC3204_rset(50, 0x75);
    AIC3204_rset(32, 0x1c);
    AIC3204_rset(33, 0x2f);
    AIC3204_rset(34, 0x50);
    AIC3204_rset(36, 0x1c);
    AIC3204_rset(37, 0x2f);
    AIC3204_rset(38, 0x50);
    AIC3204_rset(40, 0x1c);
    AIC3204_rset(41, 0x2f);
    AIC3204_rset(42, 0x50);
    //end


    AIC3204_rset( 64, 0x13);//C left filter coefficients
    AIC3204_rset(65, 0xaf);
    AIC3204_rset(66, 0x26);
    AIC3204_rset(68, 0xe7);
    AIC3204_rset(69, 0xe4);
    AIC3204_rset(70, 0x75);
    AIC3204_rset(52, 0x1c);
    AIC3204_rset(53, 0x2f);
    AIC3204_rset(54, 0x50);
    AIC3204_rset(56, 0x1c);
    AIC3204_rset(57, 0x2f);
    AIC3204_rset(58, 0x50);
    AIC3204_rset(60, 0x1c);
    AIC3204_rset(61, 0x2f);
    AIC3204_rset(62, 0x50);





    AIC3204_rset(0, 0);
    AIC3204_rset( 0x3c, 23);    // enable DAC block 23

    AIC3204_rset( 0, 0 );
    USBSTK5515_wait( 200 );        // Wait
    /* I2S settings */
    I2S0_SRGR = 0x00;
    I2S0_CR = 0x8010;    // 16-bit word, slave, enable I2C
    I2S0_ICMR = 0x3f;    // Enable interrupts

}

int cap(int n){
    if(n < N_table) return n;
    else if(n < 2*N_table) return 2*N_table -n-1;
    else if(n < 3*N_table) return n - 2*N_table;
    else return 4*N_table-n-1;
 }


int sign(int n){
    if (n < N_sample/2) return 1;
    else return -1;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  main( )                                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
 main( void )
{
   Int16 sample;
        Int16 key;
        Int16 ii;
        //Uint8 cmd[10]; // For multibyte commands
    /* Initialize BSL */
    SYS_EXBUSSEL = 0x6100;
    USBSTK5515_init( );
    AIC3204_config(freq_48);


 /* Initialize I2C */
 USBSTK5515_I2C_init( );
 //* Initialize LCD power */ --> Entire LCD routine not known
 USBSTK5515_GPIO_setDirection( 12, 1 ); // Output
 USBSTK5515_GPIO_setOutput( 12, 1 ); // Enable 13V




 /* Fill page 0*/
 OSD9616_send(0x00,0x00); // Set low column address

 for(ii=0;ii<128;ii++)
 {
 OSD9616_send(0x40,0xff);
 }

 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address




    //int sample;
    while(TRUE)
    {

        key = Get_Sar_Key();
        printf("%d", key);
        if((key == SW1))   // If SW1 pressed
        {
            if(i==7){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address



            }
            else if(i==0){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }
            else if(i==1){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }
            else if(i==2){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }

            else if(i==3){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }

            else if(i==4){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }

            else if(i==5){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }

            else if(i==6){
                 /* Write to page 0( Vietnamese) */
 OSD9616_send(0x00,0x00); // Set low column address

            }


            i++;
            if(i==10)
              i=0;
        }
        if((key == SW2))   // If SW1 pressed
        {
            if(j==2){

 OSD9616_send(0x00,0x00); // Set low column address
 AIC3204_rset(0x3c, 0x17);

            }
            else if(j==0){

 OSD9616_send(0x00,0x00); // Set low column address
 AIC3204_rset(0x3c, 0x17);

            }
            else if(j==1){

 OSD9616_send(0x00,0x00); // Set low column address

 AIC3204_rset(0, 0);
 AIC3204_rset(0x3c, 0x14);

            }
            j++;
            if(j==3)
              j=0;
        }
 double temp = 0;
int sin_sample;
int tri_sample;
int square_sample;
      for(sample=0;sample<N_sample;sample=sample+sample_skip[i])
        {   sin_sample = sign(sample)*sinetable[cap(sample)];
            temp = sign(sample)*(131068/N_sample)*(sample_skip[i]);
            tri_sample  = tri_sample + temp;
            square_sample = sign(sample)*(32767);

            while((Xmit & I2S0_IR)==0); // Wait for transmit interrupt to be pending
            if(j==0){
            I2S0_W0_MSW_W=(sin_sample);
            I2S0_W1_MSW_W=(sin_sample);
            }
            else if(j==1){
            I2S0_W0_MSW_W=(square_sample);
            I2S0_W1_MSW_W=(square_sample);
            }
            else{
            I2S0_W0_MSW_W=(tri_sample);
            I2S0_W1_MSW_W=(tri_sample);
            }

        }
    }
    /* Disble I2S */
    I2S0_CR = 0x00;
    return 0;
}
