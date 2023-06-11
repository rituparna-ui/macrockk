#include <Keypad.h>
#include <Keyboard.h>
int mode = 1;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setMode(char key) {
  switch (key) {
    case 'D': mode = 0; break;
    case 'A': mode = 1; break;
    case 'B': mode = 2; break;
    case 'C': mode = 3; break;
  }
}
void mode0(char key) {
  switch (key) {
    case '1': Keyboard.print("https://rituparnawarwatkar.com"); break;
    case '2': Keyboard.print("https://rituparnawarwatkar.com/assets/resume.pdf"); break;
    case '3': Keyboard.print("https://github.com/rituparna-ui"); break;
    case '4': Keyboard.print("rwarwatkar@gmail.com"); break;
    case '5': Keyboard.print("https://www.linkedin.com/in/rituparna-warwatkar/"); break;
  }
}

void mode1(char key) {
  switch (key) {
    case '1':
      Keyboard.print("List<Integer> ans = new ArrayList<>();");
      break;

    case '2':
      Keyboard.print("System.out.println();");
      Keyboard.write(KEY_LEFT_ARROW);
      Keyboard.write(KEY_LEFT_ARROW);
      break;

    case '3':
      Keyboard.print("console.log();");
      Keyboard.write(KEY_LEFT_ARROW);
      Keyboard.write(KEY_LEFT_ARROW);
      break;
  }
}

void handleMacros(char key) {
  if (mode == 0) {
    mode0(key);
    return;
  }
  if (mode == 1) {
    mode1(key);
    return;
  }
  if (mode == 2) { return; }
  if (mode == 3) { return; }
}
void handleKeystroke(char key) {
  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
    setMode(key);
    return;
  }
  handleMacros(key);
}
void setup() {
  Serial.begin(9600);
}
void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) { handleKeystroke(key); }
}
