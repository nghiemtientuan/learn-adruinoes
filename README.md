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

