const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int h = 9;

int dig1 = 10;
int dig2 = 11;
int dig3 = 12;

int Fnd_seg[10][8] = {
  {1, 0, 0, 0, 1, 0, 0, 0}, //0, g off
  {1, 1, 1, 1, 1, 0, 0, 1}, //1, b, c on
  {0, 1, 0, 0, 1, 1, 0, 0}, //2, f, c off
  {0, 1, 1, 0, 1, 0, 0, 0}, //3, f, e off
  {0, 0, 1, 1, 1, 0, 0, 1}, //4, a, e, d off
  {0, 0, 1, 0, 1, 0, 1, 0}, //5, b, e off
  {0, 0, 0, 0, 1, 0, 1, 0}, //6, b off
  {1, 1, 1, 1, 1, 0, 0, 0}, //7, a, b, c on
  {0, 0, 0, 0, 1, 0, 0, 0}, //8
  {0, 0, 1, 0, 1, 0, 0, 0}, //9, e off
};

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
}

void Fnd_Write(int row) {
  int seg_Pin = 2;

  for(int segPos = 0;segPos < 8;segPos++) {
    digitalWrite(seg_Pin, Fnd_seg[row][segPos]);
    seg_Pin++;
  }
}

void loop() {
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);

  for(int count = 0;count < 10;count++) {
    Fnd_Write(count);
    delay(1000);
  }
}
