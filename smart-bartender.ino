#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


////////////////////////////////////////////////////////
//                     CONSTANTS                      //
////////////////////////////////////////////////////////

LiquidCrystal_I2C lcd(0x27, 20, 4); // Set the LCD address to 0x27 for a 20 chars and 4 line display

const unsigned selectBtnPin = 3; // Select btn
const unsigned rightBtnPin = 2; // Right btn
const unsigned leftBtnPin = 4; // Left btn

byte leftHead[8] = { // Left arrow head char
  0b00010,
  0b00110,
  0b01111,
  0b11111,
  0b11111,
  0b01111,
  0b00110,
  0b00010
};
byte rightHead[8] = { // Right arrow head char
  0b01000,
  0b01100,
  0b11110,
  0b11111,
  0b11111,
  0b11110,
  0b01100,
  0b01000
};
byte arrowBody[8] = { // Arrow body char
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b00000
};


////////////////////////////////////////////////////////
//                  AUXILIARY FUNCTIONS               //
////////////////////////////////////////////////////////

void clearLine(unsigned short line){
  lcd.setCursor(0, line);
  for(int col = 0; col < 20; col ++)
    lcd.print(" ");
}


////////////////////////////////////////////////////////
//                  BARTENDER CLASS                   //
////////////////////////////////////////////////////////

class SmartBartender{
  //////////
  //PUBLIC//
  //////////
  public:
  SmartBartender(){ // Constructor
    m_currentMenu = 0;
    m_currentMenuItem = 0;
    m_menuList[0] = m_mainMenu;
    m_menuList[1] = m_drinkMenu;
  }
    
  void printMenu(){ // Print to LCD the current menu option0
    lcd.setCursor(0,0);
    lcd.print("Smart Bartender");
    lcd.setCursor(0,1);
    switch(m_currentMenu){
      case 0:
        lcd.print("Menu Principale:");
        break;
      case 1:
        lcd.print("Drink:");
        break;
    }
    lcd.setCursor(0,2);
    unsigned blanks = (20 - m_menuList[m_currentMenu][m_currentMenuItem].length()) / 2;
    for(int blank = 0; blank < blanks; blank++)
      lcd.print(" ");
    lcd.print(m_menuList[m_currentMenu][m_currentMenuItem]);
    lcd.setCursor(0,3);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.setCursor(9,3);
    lcd.print("OK");
    lcd.setCursor(18, 3);
    lcd.write(byte(1));
    lcd.write(byte(2));
  }
    
  void btnPressed(unsigned btnPin){
    switch(btnPin){
      // Select button pressed
      case selectBtnPin:
        if(m_currentMenu == 0){ // main menu
          clearLine(1);
          if(m_currentMenuItem == 0){ // drink selected
            m_currentMenu = 1;
            m_currentMenuItem = 0;
          }
        }
      break;
      // Right button pressed
      case rightBtnPin:
        clearLine(2);
        if(m_currentMenuItem + 1 < m_menuSize[m_currentMenu]) // avoid going out of range and wrap around the array
          m_currentMenuItem++;
        else
          m_currentMenuItem = 0;
      break;
      // Left button pressed
      case leftBtnPin:
        clearLine(2);
        if(m_currentMenuItem <= 0) // avoid going out of range
          m_currentMenuItem = m_menuSize[m_currentMenu] - 1;  // avoid going out of range and wrap around the array
        else
          m_currentMenuItem--;
      break;
    }
  }
  ///////////
  //PRIVATE//
  ///////////
  private:
  unsigned m_currentMenu; // index of the current menu
  unsigned m_currentMenuItem; // item's index in the current menu
  String* m_menuList[2]; // Array of pointers to the menus
  String m_mainMenu[2] = {"Drink", "Impostazioni"}; // Main menu
  String m_drinkMenu[6] = {"Coca Malibu", "Coca Monte", "Gin Tonic", "Gin Lemon", "Vodka Tonic", "Vodka Lemon"}; // Drink menu
  unsigned m_menuSize[2] = { 2, 6 }; // array containing the size of the menu arrays
};


SmartBartender sb = SmartBartender();

void setup() {
  // Debug output
  Serial.begin(9600);
  
  // Initialize digital inputs:
  pinMode(selectBtnPin, INPUT);
  pinMode(rightBtnPin, INPUT);
  pinMode(leftBtnPin, INPUT);
  
  // Initialize the LCD
  lcd.begin();
  
  // Initialize special characters
  lcd.createChar(0, leftHead); // left head char as byte(0)
  lcd.createChar(1, arrowBody); // body char as byte(1)
  lcd.createChar(2, rightHead); // right head char as byte(0)

  // Welcome the user
  lcd.setCursor(5, 1);
  lcd.print("Benvenuto!");
  delay(3000);
  lcd.clear();
  sb.printMenu();
}

void loop() {
  int pinPressed = -1;
  if(digitalRead(selectBtnPin) == HIGH){
    pinPressed = selectBtnPin;
    }
  else if (digitalRead(rightBtnPin) == HIGH){
    pinPressed = rightBtnPin;
    }
  else if (digitalRead(leftBtnPin) == HIGH){
    pinPressed = leftBtnPin;
    }
  if(pinPressed != -1){ // If something was pressed
    sb.btnPressed(pinPressed); // Notify bartender
    sb.printMenu(); // Print new menu option
    delay(200);
    }
  }
