int leds[] = {2, 3, 4, 5, 6, 7, 8};
int ledNumber = sizeof(leds)/sizeof(int);

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i <= ledNumber - 1; i = i + 1) {
  	pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }
}

void loop()
{
  Serial.println("start!!!");
  // Tat den tu 1 - 7
  for (int i = 0; i <= ledNumber - 1; i = i + 1) {
  	delay(500);
    digitalWrite(leds[i], LOW);
  }

  // Sang den tu 1 - 7
  for (int i = ledNumber - 1; i >= 0; i = i - 1) {
    delay(500);
    digitalWrite(leds[i], HIGH);
  }

  // chan sang, le tat, nguoc lai, lap lai 5 lan
  int chopTime = 5;
  for (int time = 0; time <= chopTime - 1; time = time + 1) {
    for (int i = ledNumber - 1; i >= 0; i = i - 1) {
      if (i % 2 == 0) {
      	digitalWrite(leds[i], time % 2 == 0 ? HIGH : LOW);
      }

      if (i % 2 != 0) {
      	digitalWrite(leds[i], time % 2 == 0 ? LOW : HIGH);
      }
    }

    delay(300);
  }

  // so bong sang tang dan
  for (int ledsang = 1; ledsang <= ledNumber; ledsang = ledsang + 1) {
    for (int i = 0; i <= ledNumber - 1; i = i + 1) {
    	digitalWrite(leds[i], i <= ledsang - 1 ? HIGH : LOW);
  	}
    delay(1000);

    for (int i = 0; i <= ledNumber - 1; i = i + 1) {
    	digitalWrite(leds[i], i <= ledsang - 1 ? LOW : HIGH);
  	}
    delay(1000);
  }

  // sang tu giua sang ra ngoai
  // tat all leds
  for (int i = 0; i <= ledNumber - 1; i = i + 1) {
    digitalWrite(leds[i], LOW);
  }
  delay(600);
  int middle = ledNumber/2; // 3
  for (int step = 0; step <= middle; step = step + 1) {
    digitalWrite(leds[middle + step], HIGH);
    if (ledNumber % 2 == 0) {
      digitalWrite(leds[middle - step - 1], HIGH);
    } else {
      digitalWrite(leds[middle - step], HIGH);
    }

    delay(600);
  }

  // sang theo so thu tu
  // tat all leds
  for (int i = 0; i <= ledNumber - 1; i = i + 1) {
    digitalWrite(leds[i], LOW);
  }
  for (int i = 0; i <= ledNumber - 1; i = i + 1) {
    for (int step = 1; step <= i + 1; step = step + 1) {
      digitalWrite(leds[i], HIGH);
      delay(300);
      digitalWrite(leds[i], LOW);
      delay(300);
    }
  }
  for (int i = 0; i <= ledNumber - 1; i = i + 1) {
    for (int step = 1; step <= i + 1; step = step + 1) {
      // sang den
      for (int ledIndex = 0; ledIndex <= i; ledIndex = ledIndex + 1) {
        digitalWrite(leds[ledIndex], HIGH);
      }
      delay(300);

      // tat den
      for (int ledIndex = 0; ledIndex <= i; ledIndex = ledIndex + 1) {
        digitalWrite(leds[ledIndex], LOW);
      }
      delay(300);
    }
  }

  for (int time = 0; time <= chopTime - 1; time = time + 1) {
    // sang all leds
    for (int i = 0; i <= ledNumber - 1; i = i + 1) {
      digitalWrite(leds[i], HIGH);
    }
    delay(600);

    // tat all leds
    for (int i = 0; i <= ledNumber - 1; i = i + 1) {
      digitalWrite(leds[i], LOW);
    }
    delay(600);
  }

  delay(2000);
}