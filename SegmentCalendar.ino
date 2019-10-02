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

int d1row = 0;
int d2row = 0;
int d3row = 0;

int Fnd_seg[10][8] = {
  {1, 0, 0, 0, 1, 0, 0, 0},//0
  {1, 1, 1, 1, 1, 0, 0, 1},//1
  {0, 1, 0, 0, 1, 1, 0, 0},//2
  {0, 1, 1, 0, 1, 0, 0, 0},//3
  {0, 0, 1, 1, 1, 0, 0, 1},//4
  {0, 0, 1, 0, 1, 0, 1, 0},//5
  {0, 0, 0, 0, 1, 0, 1, 0},//6
  {1, 1, 1, 1, 1, 0, 0, 0},//7
  {0, 0, 0, 0, 1, 0, 0, 0},//8
  {0, 0, 1, 0, 1, 0, 0, 0},//9
};

int day_of_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);

  d1row = 1;
  d2row = 0;
  d3row = 2;
}

void dig1_Find_Write(int d1row) {
  int seg_Pin = 2;
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, HIGH);
  for (int segPos = 0; segPos < 8; segPos++) {
    digitalWrite(seg_Pin, Fnd_seg[d1row][segPos]);
    seg_Pin++;
  }
}

void dig2_Find_Write(int d2row) {
  int seg_Pin = 2;
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, LOW);
  for (int segPos = 0; segPos < 8; segPos++) {
    digitalWrite(seg_Pin, Fnd_seg[d2row][segPos]);
    seg_Pin++;
  }
}

void dig3_Find_Write(int d3row) {
  int seg_Pin = 2;

  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, LOW);
  for (int segPos = 0; segPos < 8; segPos++) {
    digitalWrite(seg_Pin, Fnd_seg[d3row][segPos]);
    seg_Pin++;
  }
}

void loop() {
  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  if (hours == 0 && (minutes == 0 && seconds == 0)) {
    d3row += 1;
    if (days > day_of_month[month - 1]) {
      d3row = 1;
      d1row += 1;
    }
  }

  if (month >= 10 && month <= 12) {
    for (int i = 0; i < 50; i++) {
      dig1_Find_Write(d1row);
      delay(5);
      dig2_Find_Write(d2row);
      delay(5);
      dig3_Find_Write(d3row);
      delay(5);
    }
    if (d2row == 10) {
      d2row = 0;
    }
    if (d3row == 10) {
      d3row = 0;
    }
  }
  else if (month > 12) {
    d1row = 1;
    d3row = 1;
    d2row = 0;
  }

}
