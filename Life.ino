const int n=20;
int pole1[n][n];
int pole2[n][n];
int tk; int t;
int i; int j; int s;

void setup() {
  for (i = 1; i<=n; i++) {
    for (j = 1; j<=n; j++) {
      pole1[i][j] = 0;
    }
  }
  for (i = 1; i<=n; i++) {
    for (j = 1; j<=n; j++) {
      pole2[i][j] = pole1[i][j];
    }
  }
  tk = 25;
  pole1[12][10] = 1;
  pole1[13][11] = 1;
  pole1[14][9] = 1; pole1[14][10] = 1; pole1[14][11] = 1;
  Serial.begin(9600);
}

int sosedi(int i, int j, int pole1[n][n]){
  int im = i - 1;
  int ip = i + 1;
  int jm = j - 1;
  int jp = j + 1;
  if (im = 0) im = n;
  if (ip > n) ip = 1;
  if (jm = 0) jm = n;
  if (jp > n) jp = 1;
  int a = pole1[im][jm] + pole1[im][j] + pole1[im][jp] + pole1[i][jm] + 0 + pole1[i][jp] + pole1[ip][jm] + pole1[ip][j] + pole1[ip][jp];
  return a;
}

void PrintPole(int* pole1[n][n]){
  for (i = 1; i<=n; i++){
    for (j = 1; j<=n; j++){
      if (pole1[i][j] == 1) Serial.print('*');
        else Serial.print(' ');
    }
      Serial.println();
  }
}

void GameOfLife(){
    for (t = 0; t<=tk; t++){
      for (i = 1; i<=n; i++){
        for (j = 1; j<=n; j++){
          s = sosedi(i, j, pole1);
          if (pole1[i][j] == 0) 
            if (s == 3) pole2[i][j] = 1;
          if (pole1[i][j] == 1) { 
            if ((s == 2) or (s == 3)) pole2[i][j] = 1; 
              else pole2[i][j] = 0;
          }
        }
       }
     }        
    for (i = 1; i<=n; i++) {
    for (j = 1; j<=n; j++) {
      pole1[i][j] = pole2[i][j];
    }
  }
    delay(500);
}

void loop() {
  GameOfLife;
  PrintPole(pole1);
}
