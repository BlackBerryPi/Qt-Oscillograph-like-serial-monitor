void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int val = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.write(0x05);
  if(val<0xff) {
    val+=8;
  } else {
    val = 0;
  }

  for(int j=0; j<val; j++) {
    Serial.write(j);
  }
}
