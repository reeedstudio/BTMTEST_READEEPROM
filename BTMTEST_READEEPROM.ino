// DEMO OF EEPROM TEST OF BTM
#include <EEPROM.h>
#include <Wire.h>

#include "eeprom_manage.h"
#include "BTMGlobalDfs.h"

void readVol()
{
    int volX[8];
    float volY[8];
    float volY_n[8];
    
    for(int i = 0; i<8; i++)        // volX
    {
        EEPM.read(EEPADDRVOLX  +2*i, &volX[i], sizeof(int));
        EEPM.read(EEPADDRVOLY  +4*i, &volY[i], sizeof(float));
        EEPM.read(EEPADDRVOLY_N+4*i, &volY_n[i], sizeof(float));
    }
    
    Serial.println("----------VOL DATA:----------");
    
    Serial.print("volX:\t");
    for(int i = 0; i<8; i++)
    {
        Serial.print(volX[i]);
        Serial.print("\t\t");
        if(i>=5)Serial.print("\t");
    }
    
    Serial.print("\r\nvolY:\t");
    for(int i = 0; i<8; i++)
    {
        Serial.print(volY[i]);
        Serial.print("\t\t");
    }
        
    Serial.print("\r\nvolY_n:\t");
    for(int i = 0; i<8; i++)
    {
        Serial.print(volY_n[i]);
        Serial.print("\t\t");
    }
    Serial.println();
    
}

void readOhm()
{
    long ohmX[8];
    float ohmY[8];
    
    for(int i = 0; i<8; i++)
    {
        EEPM.read(EEPADDROHMX  +4*i, &ohmX[i], sizeof(long));
        EEPM.read(EEPADDROHMY  +4*i, &ohmY[i], sizeof(float));
    }
    
    
    Serial.println("----------OHM DATA:----------");
    
    Serial.print("ohmX:\t");
    for(int i = 0; i<8; i++)
    {
        Serial.print(ohmX[i]);
        Serial.print('\t');
    }
    
    Serial.print("\r\nvolY:\t");
    for(int i = 0; i<8; i++)
    {
        Serial.print(ohmY[i]);
        Serial.print('\t');
    }
    Serial.println();
    
}

void readAmp()
{
    int ampX[4];
    float ampY[4];
    float ampY_n[4];
    
    for(int i = 0; i<4; i++)        // ampX
    {
        EEPM.read(EEPADDRAMPX  +2*i, &ampX[i], sizeof(int));
        EEPM.read(EEPADDRAMPY  +4*i, &ampY[i], sizeof(float));
        EEPM.read(EEPADDRAMPY_N+4*i, &ampY_n[i], sizeof(float));
    }
    
    Serial.println("----------AMP DATA:----------");
    
    Serial.print("ampX:\t");
    for(int i = 0; i<4; i++)
    {
        Serial.print(ampX[i]);
        Serial.print('\t');
    }
    
    Serial.print("\r\nampY:\t");
    for(int i = 0; i<4; i++)
    {
        Serial.print(ampY[i]);
        Serial.print('\t');
    }
        
    Serial.print("\r\nampY_n:\t");
    for(int i = 0; i<4; i++)
    {
        Serial.print(ampY_n[i]);
        Serial.print('\t');
    }
    Serial.println();
}

void readMAMP()
{
    int mampX[2];
    float mampY[2];
    float mampY_n[2];
    
    for(int i = 0; i<2; i++)
    {
        EEPM.read(EEPADDRMAMPX  +2*i, &mampX[i], sizeof(int));
        EEPM.read(EEPADDRMAMPY  +4*i, &mampY[i], sizeof(float));
        EEPM.read(EEPADDRMAMPY_N+4*i, &mampY_n[i], sizeof(float));
    }
    
    Serial.println("----------MAMP DATA:----------");
    
    Serial.print("ampX:\t");
    for(int i = 0; i<2; i++)
    {
        Serial.print(mampX[i]);
        Serial.print("\t\t");
    }
    
    Serial.print("\r\nampY:\t");
    for(int i = 0; i<2; i++)
    {
        Serial.print((long)mampY[i]);
        Serial.print("\t\t");
    }
        
    Serial.print("\r\nmampY_n:\t");
    for(int i = 0; i<2; i++)
    {
        Serial.print((long)mampY_n[i]);
        Serial.print("\t\t");
    }
    Serial.println();
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
    

}

void loop()
{
    
}
