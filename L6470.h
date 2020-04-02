#ifndef L6470_H
#define L6470_H

#include <Arduino.h>
#include <SPI.h>

//(2)ステッピングモーター用のピンの定義
#define PIN_SPI_MOSI 23
#define PIN_SPI_MISO 19
#define PIN_SPI_SCK 18
#define PIN_SPI_SS1 5
#define PIN_SPI_SS2 17


class L6470
{
    public:
        typedef enum{
            ABS_POS     =   0x01,
            EL_POS      =   0x02,
            MARK        =   0x03,
            SPEED       =   0x04,
            ACC         =   0x05,
            DeC         =   0x06,
            MAX_SPEED   =   0x07,
            MIN_SPEED   =   0x08,
            KVAL_HOLD   =   0x09,
            KVAL_RUN    =   0x0A,
            KVAL_ACC    =   0x0C,
            INT_SPD     =   0x0D,
            ST_SLP      =   0x0E,
            N_SLP_ACC   =   0x0F,
            FN_SLP_DEC  =   0x10,
            K_THERM     =   0x11,
            ADC_OUT     =   0x12,
            OCD_TH      =   0x13,
            STALL_TH    =   0x14,
            FS_SPD      =   0x15,
            STEP_MODE   =   0x16,
            ALARM_EN    =   0x17,
            CONFIG      =   0x18,
            STATUS      =   0x19
        } RegisterAdress;

        L6470();
        void SendOneByte();
        void SetupOneDriver();
        void Run(bool foward, int speed);
        void HardStop();  

        void SetupTwoDrivers();
        void GoForward();
        void GoBack();
        void TurnRight();
        void TurnLeft();
};

#endif
