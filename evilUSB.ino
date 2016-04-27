// teensy 3.1

int PIN_LED = 13;
int PIN_BUTTON = 7;

// loop effects
int start = 0;
int BLINK_DELAY = 250;
int BUTTON_DELAY = 1500;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  digitalWrite(PIN_LED, HIGH);
}

class Commands {
  public:
    static void Type(String chars) {
      Keyboard.print(chars);
      delay(20);
      Keyboard.println("");
    }
    static void OpenTerminal() {
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
      Keyboard.send_now();
      Keyboard.set_key1(KEY_T);
      Keyboard.send_now();
      Keyboard.set_modifier(0);
      Keyboard.set_key1(0);
      Keyboard.send_now();
      delay(200);
    }
    static void RunLinux(String cmd) {
      Keyboard.set_modifier(MODIFIERKEY_ALT);
      Keyboard.send_now();
      Keyboard.set_key1(KEY_F2);
      Keyboard.send_now();
      Keyboard.set_modifier(0);
      Keyboard.set_key1(0);
      delay(50);
      Keyboard.send_now();
      Keyboard.print(cmd);
      Keyboard.set_key1(KEY_ENTER);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    }
    static void RunWindows(String cmd) {
      // Irongeek's PHUKD Library
      Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI); //Windows key
      Keyboard.set_key1(KEY_R); // use r key
      Keyboard.send_now(); // send strokes
      Keyboard.set_modifier(0); //prep release of control keys
      Keyboard.set_key1(0); //have to do this to keep it from hitting key multiple times.
      Keyboard.send_now(); //Send the key changes
      delay(500);
      Keyboard.print(cmd);
      Keyboard.set_key1(KEY_ENTER);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    }
    static void Finish() {
      BLINK_DELAY = 1000;
    }
};

class Actions {
  public:
    static void Linux() {
      delay(500);
      Commands::RunLinux("wget -q http://slacy.me -O test.tmp");
      Commands::Finish();
    }
    static void Windows() {
      delay(500);
      Commands::RunWindows("chrome");
      Commands::Finish();
    }
    static void Osx() {
    }
};

// loop


void loop() {
  // flash when done
  if (start == 1) {
    digitalWrite(PIN_LED, HIGH);
    delay(BLINK_DELAY);
    digitalWrite(PIN_LED, LOW);
    delay(BLINK_DELAY);
  }
  else {
    digitalWrite(PIN_LED, HIGH);
  }

  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_LED, LOW);
    delay(BUTTON_DELAY);
    if (digitalRead(PIN_BUTTON) == LOW) {
      // still held
      Actions::Windows();
      start = 1;
      return;
    }
    // just clicked
    Actions::Linux();
    start = 1;
  }
}
