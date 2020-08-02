//by Acha
//https://github.com/acha666/ESP8266-DHT
#define BLINKER_PRINT    Serial
#define BLINKER_WIFI

#include <Blinker.h>
#include <DHT.h>

//--------配置部分开始--------//

char auth[] = "571f97646be4";      //你的点灯Auth Key
char ssid[] = "MeiYouMiMa_2.4G";   //你的WIFI名
char pswd[] = "MeiYouMiMa456";     //你的WIFI密码

#define DHTPIN 4          //DHT模块端口

//选择模块类别
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

BlinkerNumber HUMI("num-123");   //替换为湿度数据键名
BlinkerNumber TEMP("num-456");   //替换为温度数据键名

//--------配置部分结束--------//

DHT dht(DHTPIN, DHTTYPE);

int humi_read = 0, temp_read = 0;

void heartbeat()
{
  HUMI.print(humi_read);
  TEMP.print(temp_read);
}
void dataStorage()
{
  Blinker.dataStorage("temp", temp_read);
  Blinker.dataStorage("humi", humi_read);
}

void setup()
{
  Serial.begin(115200);

#if defined(BLINKER_PRINT)
  BLINKER_DEBUG.stream(BLINKER_PRINT);
#endif

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Blinker.begin(auth, ssid, pswd);

  Blinker.attachHeartbeat(heartbeat);
  Blinker.attachDataStorage(dataStorage);
}

void loop()
{
  Blinker.run();
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  //BLINKER_LOG("Temp:",t,"Humidity: ",h);
  if (h > 100 || h < 0 || t < -20 || t > 80)
  {
    BLINKER_LOG("Failed to read from DHT sensor!");
  }
  else
  {
    humi_read = h;
    temp_read = t;
  }

  Blinker.delay(2000);
}
