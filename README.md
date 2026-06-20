ESP32 가변저항으로 서보모터 각도 제어하기

이번 영상에서는 ESP32와 가변저항(Potentiometer)을 이용해 서보모터의 회전 각도를 제어합니다.
가변저항을 돌리면 ESP32의 ADC가 그 값을 읽고, map() 함수로 0~180도 범위로 변환하여
서보모터가 실시간으로 따라 움직입니다.

<사용 부품>
- ESP32-WROOM (30핀)
- SG90 / MG90 서보모터
- 가변저항 (Potentiometer)
- 점퍼 와이어

<핀 연결>
- 서보 신호 → GPIO27
- 가변저항 신호(SIG) → GPIO4 (ADC)
- 서보 VCC / 가변저항 VCC → VIN(5V)
- 모든 GND → GND 공통

<사용 라이브러리>
- ESP32Servo (ESP32PWM 포함)

<핵심 코드>
analogRead()로 0~4095 값을 읽고, map(potValue, 700, 4095, 0, 180)으로
각도를 계산한 뒤 myServo.write()로 서보를 제어합니다.
map(potValue, 700, 4095, ...)에서 700은 제가 가지고 있는 가변저항의 하한 값이 700 부근이며
원래의 값은 0 입니다


ESP32 Servo Motor Control with a Potentiometer

In this video, we control the rotation angle of a servo motor using an ESP32 and a potentiometer.
As you turn the potentiometer, the ESP32's ADC reads the value, maps it to a 0–180° range,
and the servo follows the knob in real time.

<Parts>
- ESP32-WROOM (30-pin)
- SG90 / MG90 servo motor
- Potentiometer
- Jumper wires

<Wiring>
- Servo signal → GPIO27
- Potentiometer signal (SIG) → GPIO4 (ADC)
- Servo VCC / Potentiometer VCC → VIN (5V)
- All GND → common GND

<Library>
- ESP32Servo (includes ESP32PWM)

<Key Code>
Read the analog value (0–4095) with analogRead(), convert it to an angle using
map(potValue, 700, 4095, 0, 180), and drive the servo with myServo.write().
** 700 : My potentiometer has minimum value of 700, otherwise this value should 0(zero).
