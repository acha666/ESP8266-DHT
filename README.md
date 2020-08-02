# ESP8266-DHT
基于ESP8266的温湿度计模块
**注意，使用这个项目需要你具备一定能够配置Arduino IDE对于ESP8266开发环境和给ESP8266下载程序的能力**
# 库、环境依赖
* Arduino IDE以及ESP8266开发环境，不多赘述
* Blinker点灯库
  https://github.com/blinker-iot/blinker-library/archive/master.zip
  将下载好的blinker库解压到 我的电脑>文档>Arduino>libraries 文件夹中
* (adafruit/DHT-sensor-library)[https://github.com/adafruit/DHT-sensor-library]
  可在Arduino IDE库管理中搜索`DHT sensor library`,一般在第二个
# 硬件需求
* ESP8266开发板，可以是NodeMCU之类的
* 或者一个ESP8266温湿度物联网模块
* 支持的传感器：DHT11/DHT22(M2302)/DHT21(AM2301)
# 食用教程
首先，前往 https://diandeng.tech/doc/app-download 下载APP并注册
## 创建一个新项目
右上角加号-独立设备-WIFI接入。服务商随便
![](https://github.com/acha666/ESP8266-DHT/blob/master/pic/1.png)
记下AuthKey
回到主页面进入设备，点击右上角编辑按钮
添加两个`数据`模组，可以拖动位置，可以点击模组然后更改外观
![](https://github.com/acha666/ESP8266-DHT/blob/master/pic/2.png)
记下每个模块左上角的字母名称，然后右上角锁定
回到程序，在规定的自定义区域里面修改相应的值
``` c
//--------配置部分开始--------//

char auth[] = "abcdefghi12";      //你的点灯Auth Key
char ssid[] = "WIFI";   //你的WIFI名
char pswd[] = "123456";     //你的WIFI密码

#define DHTPIN 4          //DHT模块端口

//选择模块类别
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

BlinkerNumber HUMI("num-123");   //替换为湿度数据键名
BlinkerNumber TEMP("num-456");   //替换为温度数据键名

//--------配置部分结束--------//
```
完成后连接开发板，在`项目`菜单中设置好串口号等属性，然后使用Ctrl+U下载程序到开发板
打开串口调试工具，波特率115200，然后按reset键重启开发板
等到串口输出MQTT服务已连接即可。在APP中刷新，设备应该已经连接并且有温度湿度数值