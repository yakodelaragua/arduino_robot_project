#define SCL_Pin A5 //Clock
#define SDA_Pin A4 //data

unsigned char smile[] = {0x00, 0x00, 0x0c, 0x02, 0x02, 0x22, 0x4c, 0x40, 0x40, 0x4c, 0x22, 0x02, 0x02, 0x0c, 0x00, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

unsigned char cara_corazon[] = {0x00, 0x00, 0x0c, 0x12, 0x24, 0x12, 0x0c, 0x00, 0x00, 0x0c, 0x12, 0x24, 0x12, 0x0c, 0x00, 0x00};

unsigned char corazon[] = {0x00, 0x00, 0x00, 0x0e, 0x11, 0x21, 0x42, 0x84, 0x42, 0x21, 0x11, 0x0e, 0x00, 0x00, 0x00, 0x00};


void setup() {
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(clear);

}

void loop() {
  matrix_display(smile);

}

void matrix_display(unsigned char matrix_value[]) {
  IIC_start(); //Empezar a mandar datos
  IIC_send(0xc0); //select an address

  for (int i = 0; i < 16; i++) //image data have 16 characters
  {
  IIC_send(matrix_value[i]); //data to transmit pictures
  }

  IIC_end();

  IIC_start();
  IIC_send(0x8A); //show control and select pulse width 4/16
  IIC_end();
}

void IIC_start() {
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW); 

}

void IIC_send(unsigned char send_data) {
  for (byte mask = 0x01; mask != 0; mask <<= 1) {
    
    if (send_data & mask) { //Encender o apagar luz
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //pull up the clock pin SCL_Pin to end the transmission of data
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //pull down the clock pin SCL_Pin to change signals of SDA

  }
}

void IIC_end() {
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
