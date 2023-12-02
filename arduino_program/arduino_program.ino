const int chipSelect = 10;
/*
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4   
 */
#include <SdFat.h>
#include <Arduino_LSM9DS1.h>
SdFat sd;
SdFile myFile;
int i = 0;

char fileName[] = "data.txt";
//int sdPower = 3;

void setup() 
{  
  Serial.begin(9600);

  // Wait for USB Serial
  /*while (!Serial) {
    yield();
  }*/
  //pinMode(sdPower,OUTPUT);
  if (!IMU.begin()) {
    //Serial.println("Failed to initialize IMU!");
    while (1);
  }

  while(!sd.begin(chipSelect, SPI_HALF_SPEED)){
    //Serial.println("fuck");
  }
  //Serial.println("successfulInit");
}

void loop() 
{  
  //digitalWrite(3,HIGH);
  
  myFile.open(fileName, O_RDWR | O_CREAT | O_AT_END);
  //Serial.println("writing a hello world line");
  //myFile.println("Hello ");
  float x, y, z;
  //struct xyz buf[128];

  //while(i < 128){

    //struct xyz gyroM;
    //if (IMU.gyroscopeAvailable()) {
    while(!IMU.gyroscopeAvailable()){
      Serial.println("gyro unavailable");
    }
      IMU.readGyroscope(x, y, z);
      //myFile.println("writing gyro line");
      //myFile.FsBaseFile::flush();
      //Serial.println("writing gyro line ");
      Serial.println(i);

      myFile.print(x);
      myFile.print(" , ");
      myFile.print(y);
      myFile.print(" , ");
      myFile.print(z);
      myFile.print(" , ");
      myFile.println(i);
      //buf[i] = gyroM;
      i++;

    //}
    
  //Serial.println("writing buf");
  //myFile.write(buf, 128*3*sizeof(float));
  //myFile.println(buf);
  //myFile.FsBaseFile::flush();
  myFile.sync();
  myFile.close();  

  //digitalWrite(3,LOW);
  //NOT ALWAYS WRITING? UNSURE
  //delay(1);  
}