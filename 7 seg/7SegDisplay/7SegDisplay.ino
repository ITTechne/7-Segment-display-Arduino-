// a= pin8; b= pin9; c= pin3; d= pin5; e= pin4; f= pin7; g= pin6; DP= pin2;
//array to save numbers
// can change depending on how it is wired up
int number_array[10][7] = {
  //in arry format segments will turn on as follow
  //{b, c, e, d, g, f, a}
  {1, 1, 1, 1, 0, 1, 1},//0
  {1, 1, 0, 0, 0, 0, 0},//1
  {1, 0, 1, 1, 1, 0, 1},//2
  {1, 1, 0, 1, 1, 0, 1},//3
  {1, 1, 0, 0, 1, 1, 0},//4
  {0, 1, 0, 1, 1, 1, 1},//5
  {0, 1, 1, 1, 1, 1, 1},//6
  {1, 1, 0, 0, 0, 0, 1},//7
  {1, 1, 1, 1, 1, 1, 1},//8
  {1, 1, 0, 0, 1, 1, 1},//9
};

void setup() {
  // put your setup code here, to run once:
 pinMode(2, OUTPUT);//DP
 pinMode(3, OUTPUT);//c
 pinMode(4, OUTPUT);//e
 pinMode(5, OUTPUT);//d
 pinMode(6, OUTPUT);//g
 pinMode(7, OUTPUT);//f
 pinMode(8, OUTPUT);//a
 pinMode(9, OUTPUT);//b

}

void loop() {
  // put your main code here, to run repeatedly:
  // the for loop only cycles thru 0 to 9
  for (int j = 0; j < 10; j++){
    //j can be changed for a value between 0 and 10 to choose the number you whant to display
    number_write(j);//This is the number you will display
    delay(1000);
  }
}

  void number_write(int num){
    //this part cycles thru the a row of the array and turns on all segment that are 1 and turns off all segments that are 0.
    int pin = 2;
    for (int i=0; i < 7 ; i++){
      digitalWrite(pin, number_array[num][i]);
      pin++;
    }
    digitalWrite(pin, number_array[num][0]);//Use if the b led is not turning on, else remove
  }