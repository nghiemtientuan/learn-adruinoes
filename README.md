# Intro
This are adruino exercises

[Video 1](https://www.youtube.com/watch?v=F1chhazAlVo&list=PLe-j2rpPeZ3_cm6OO5gPwJsC_MHioLmkI)

# 1. Arduino UNO main board info
Nguồn đầu vào 7-12V
Nguồn USB và nguồn VIN 5V
- Các chân digital
  - UNO có các chân từ 0-13 digital
  - 0-1 chân giao tiếp blutooth
  - 2-13 chỉ sử dụng các chân này để giao tiếp
  - Các chân có ~ có thể điều chỉnh điện áp đầu ra bằng analogWrite 0-5V
  - Các chân không có ~ chỉ có thể điều chỉnh điện áp 2 mức là 0|5V
- Các chân analog => xuất ra tín hiệu dạng analog 10 bit (0 -> 2^10 - 1) để đọc giá trị điện áp trong
khoảng 0-5V
  - có các chân từ A0 - A5
- Các chân nguồn điện
  - GND là chân mát - cực âm

# 2. Cấu trúc 1 chương trình Arduino
- function setup(): là hàm cài đặt ban đầu, khai báo các thông số ban đầu
- function loop(): là hàm lặp lại các công việc thực hiện liên tục

# 3. Functions list
- pinMode - hàm khai báo chân tín hiệu
- delay - hàm delay
- digitalWrite - hàm cài đặt giá trị digital
- if - 
- if else - 
- for - 
- sizeof - kích thước mảng, string, theo dạng byte. Để đếm số phần tử của mảng cần chia cho kiểu dữ liệu
của mảng đó để tính số phần tử. VD: sizeof(A)/sizeof(int)

# 4. led
- Cực âm là cực chân ngắn hơn, chân thẳng, bên trong bóng phần to hơn

# 5. Nạp code
- Kiểm tra board setting: Tools -> Board -> select UNO
- Compile code
- Check port: Tools -> Port -> select COM8
- Nạp code
- Error port permission:
```
sudo chmod a+rw /dev/ttyUSB0
```

# 6. Giá trị
INPUT_PULLUP: Đầu vào có gắn thêm điện trở mặc định
INPUT: Thông tin vào
OUTPUT: Truyền ra

# 7. Matrix led
[Doc](https://wiki.keyestudio.com/Ks0428_keyestudio_Mini_Tank_Robot_V2#Project_9:_LED_Expression_Panel)
[dotmatrixtool](http://dotmatrixtool.com/#)
- led matrix 16*8

# 8. millis and micros
Millis() có nhiệm vụ trả về một số – là thời gian (tính theo mili giây) kể từ lúc mạch Arduino bắt đầu chương trình 
của bạn. Nó sẽ tràn số và quay số 0 (sau đó tiếp tục tăng) sau 50 ngày.

Lưu ý quan trọng về hàm thời gian millis():

Các hàm về thời gian trong Arduino gồm millis() và micros() sẽ bị tràn số sau 1 thời gian sử dụng. Với hàm millis() 
là khoảng 50 ngày. Tuy nhiên, do là kiểu số nguyên không âm (unsigned long) nên ta dễ dàng khắc phục điều này bằng 
cách sử dụng hình thức ép kiểu.
```
unsigned long time;
byte ledPin = 10;
void setup()
{
    // khởi tạo giá trị biến time là giá trị hiện tại
    // của hàm millis();
    time = millis();
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}
void loop() 
{
    // Lưu ý các dấu ngoặc khi ép kiểu
    // đoạn chương trình này có nghĩa là sau mỗi 1000 mili giây
    // đèn Led ở chân số 10 sẽ thay đổi trạng thái
    if ( (unsigned long) (millis() - time) > 1000)
    {
            // Thay đổi trạng thái đèn led
        if (digitalRead(ledPin) == LOW)
        {
            digitalWrite(ledPin, HIGH);
        } else {
            digitalWrite(ledPin, LOW);
        }
        
        // cập nhật lại biến time
        time = millis();
    }
}
```
Thông thường, nếu ta có 2 số A, B và B lớn hơn A ( B > A) thì phép trừ thu được A-B là một số âm. Nhưng khi ép kiểu 
unsigned long là kiểu số nguyên dương, không có số âm nên giá trị trả về là 1 số nguyên dương lớn.
