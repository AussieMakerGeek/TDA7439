#ifndef TDA7439_H
#define TDA7439_H

//chip **7 bit** address
// Datasheet says 0x88 but that is the 8 bit
// address. Wire.h automatically appends the 
// extra (lsb write) bit.
#define TDA7439_address 0x44 

//Sub addresses
#define TDA7439_input_sel 0x00
#define TDA7439_input_gain 0x01
#define TDA7439_volume 0x02
#define TDA7439_bass 0x03
#define TDA7439_middle 0x04
#define TDA7439_trebble 0x05

#define TDA7439_ratt 0x06
#define TDA7439_latt 0x07

// Input selection
#define TDA7439_input_1 0x03
#define TDA7439_input_2 0x02
#define TDA7439_input_3 0x01
#define TDA7439_input_4 0x00

//TDA7439 input gain in db (x 2)
//0x00 -> 0x0F 

//TDA7439 volume (-db)
//0x00 -> 0x2F
#define TDA7439_mute 0x38  //Mute main volume

#include <Arduino.h>
class TDA7439
{
  public:
    TDA7439();
	void setInput(int input); // 1 to 4
	void inputGain(int gain); // 0 to 30
	void setVolume(int volume); // 0 to 48 ( 0 is mute)
	void setSnd(int val, int range); //-7 to +7 , 1 - Bass | 2 - Mids | 3 - Trebble
	void mute();
	void spkAtt(int att); // Output attenuation 0 to 79 (db) can be used for balance but not enabled in this code.
  private:
	void writeWire(char a, char b);
};
	
#endif //TDA7439_H
