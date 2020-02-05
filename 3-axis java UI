
  // this code is a crude template
// you will need to edit this

void setup() {
  Serial.begin(9600);
}



// or use this loop if sending floats
void loop() {
  int x_axis = analogRead(A3);
  int y_axis = analogRead(A2);

  char x_axis_text[30];
  char y_axis_text[30];

  dtostrf(x_axis, 10, 10, x_axis_text);
  dtostrf(y_axis, 10, 10, y_axis_text);

  char text[63];
  snprintf(text, 63, "%s,%s", x_axis_text, y_axis_text);
  Serial.println(text);

  delay(200);
}

