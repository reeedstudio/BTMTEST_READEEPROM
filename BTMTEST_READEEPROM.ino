// DEMO OF EEPROM TEST OF BTM
#include <EEPROM.h>
#include <Wire.h>

#include "eeprom_manage.h"
#include "BTMGlobalDfs.h"

#define SPACE   15

#define VOL     1
#define OHM     1
#define AMP     1
#define MAMP    1

#if VOL || AMP || MAMP
int dtaX[8];
#endif

#if OHM
long l_dtaX[8];
#endif

float dtaY[8];
float dtaY_n[8];

int nt = 0;
    

void dispSpace(int n)
{
    if(n>20 || n < 1)return;
    char tmp[] = "                   ";
    tmp[n] = '\0';
    Serial.print(tmp);
}

void readVol()
{
#if VOL

    for(int i = 0; i<8; i++)        // volX
    {
        EEPM.read(EEPADDRVOLX  +2*i, &dtaX[i], sizeof(int));
        EEPM.read(EEPADDRVOLY  +4*i, &dtaY[i], sizeof(float));
        EEPM.read(EEPADDRVOLY_N+4*i, &dtaY_n[i], sizeof(float));
    }
    
    Serial.println("\r\n\r\n----------VOL DATA:----------\r\n");
    
    nt = Serial.print("volX:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<8; i++)
    {
        
        nt = Serial.print(dtaX[i]);
        dispSpace(SPACE-nt);
    }
    
    Serial.println();
    nt = Serial.print("volY:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<8; i++)
    {
        nt = Serial.print(dtaY[i]);
        dispSpace(SPACE-nt);
    }
    
    Serial.println();
    nt = Serial.print("volY_n:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<8; i++)
    {
       nt = Serial.print(dtaY_n[i]);
       dispSpace(SPACE-nt);
    }
    Serial.println();
#endif
}


void readOhm()
{
#if OHM
    for(int i = 0; i<8; i++)
    {
        EEPM.read(EEPADDROHMX +4*i, &l_dtaX[i], sizeof(long));
        EEPM.read(EEPADDROHMY +4*i, &dtaY[i], sizeof(float));
    }
    
    Serial.println("\r\n\r\n----------OHM DATA:----------\r\n");
    
    nt = Serial.print("ohmX:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<8; i++)
    {
        nt = Serial.print(l_dtaX[i]);
        dispSpace(SPACE-nt);
    }
    
    Serial.println();
    nt = Serial.print("ohmY:");
    dispSpace(SPACE-nt);
    
    for(int i = 0; i<8; i++)
    {
        nt = Serial.print(dtaY[i]);
        dispSpace(SPACE-nt);
    }
    Serial.println();
#endif
}

void readAmp()
{
#if AMP
    for(int i = 0; i<4; i++)        // ampX
    {
        EEPM.read(EEPADDRAMPX  +2*i, &dtaX[i], sizeof(int));
        EEPM.read(EEPADDRAMPY  +4*i, &dtaY[i], sizeof(float));
        EEPM.read(EEPADDRAMPY_N+4*i, &dtaY_n[i], sizeof(float));
    }
    
    Serial.println("\r\n\r\n----------AMP DATA:----------\r\n");
    
    nt = Serial.print("ampX:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<4; i++)
    {
        nt = Serial.print(dtaX[i]);
        dispSpace(SPACE-nt);
    }
    
    Serial.println();
    nt = Serial.print("ampY:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<4; i++)
    {
        nt = Serial.print(dtaY[i]);
        dispSpace(SPACE-nt);
    }
    
    Serial.println();
    Serial.print("ampY_n:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<4; i++)
    {
        nt = Serial.print(dtaY_n[i]);
        dispSpace(SPACE-nt);
    }
    Serial.println();
    
#endif
}

void readMAMP()
{
#if MAMP
    for(int i = 0; i<2; i++)
    {
        EEPM.read(EEPADDRMAMPX  +2*i, &dtaX[i], sizeof(int));
        EEPM.read(EEPADDRMAMPY  +4*i, &dtaY[i], sizeof(float));
        EEPM.read(EEPADDRMAMPY_N+4*i, &dtaY_n[i], sizeof(float));
    }
    
    Serial.println("\r\n\r\n----------MAMP DATA:----------\r\n");
    
    nt = Serial.print("mampX:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<2; i++)
    {
        nt = Serial.print(dtaX[i]);
        dispSpace(SPACE-nt);
    }
    Serial.println();
    nt = Serial.print("mampY:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<2; i++)
    {
        nt = Serial.print((long)dtaY[i]);
        dispSpace(SPACE-nt);
    }
    
    Serial.println();
    nt = Serial.print("mampY_n:");
    dispSpace(SPACE-nt);
    for(int i = 0; i<2; i++)
    {
        nt = Serial.print((long)dtaY_n[i]);
        dispSpace(SPACE-nt);
    }
    Serial.println();
#endif
}
void setup()
{
    Serial.begin(38400);
    Serial.println("hello world");
  
    if(EEPROM.read(1) != 0x55)      // no configed
    {
        Serial.println("bluetooth multimeter hadn't been configed!");
        while(1);                   // die here
    }
    
    readVol();
    readOhm();
    readAmp();
    readMAMP();

}

void loop()
{
    
}
