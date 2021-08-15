//--------------------------------------------------------------------------------
// AppleTV Remote エミュレータ
// [AppleRemoteEMU.ino]
// Copyright (c) 2021 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//
// 2021/08/15 初版リリース
//
// 以下のArduinoからApple Remoteの赤外線信号を送信するライブラリを使用しています。
// ArduinoからApple Remoteの赤外線信号を送信
// https://neocat.hatenablog.com/entry/20100503/1272900070 
//--------------------------------------------------------------------------------

#include "AppleRemoteIR.h"

AppleRemoteIR ar = AppleRemoteIR(3);      // output pin => 3

// Every AppleRemote has unique ID (1-255). You can specify the id (default = 1).
//AppleRemoteIR ar = AppleRemoteIR(3, 1); // output pin => 3,
                                          // AppleRemote ID => 1

void setup()
{
  Serial.begin(115200);
  Serial.println("");
  Serial.println("AppleRemote for Arduino");
  menu();  
  Serial.print(">");
    
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  char val;
  if (Serial.available() > 0){
      val = Serial.read();
      switch(val){
        case 'h':
        case 'H':
                  menu();
                  break;
        case '8':  // UP
                  Serial.print("UP");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.up();
                  PostProcess();
                  break;
        case '2':  // DOWN
                  Serial.print("DOWN");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.down();
                  PostProcess();
                  break;
        case '4':  // LEFT
                  Serial.print("LEFT");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.left();
                  PostProcess();
                  break;
        case '6':  // RIGHT
                  Serial.print("RIGHT");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.right();
                  PostProcess();
                  break;
        case '5':  // CENTER
                  Serial.print("CENTER");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.center();
                  PostProcess();
                  break;                  
        case '0':  // MENU
                  Serial.print("MENU");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.menu();
                  PostProcess();
                  break; 
        case ',':  // PLAY/PAUSE
                  Serial.print("PLAY/PAUSE");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.play();
                  PostProcess();
                  break; 
        case '+':  // PAIR ON
                  Serial.print("PAIR ON");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.pairOn();
                  PostProcess();
                  break; 
        case '-':  // PAIR OFF
                  Serial.print("PAIR OFF");
                  digitalWrite(LED_BUILTIN, HIGH);
                  ar.pairOff();
                  PostProcess();
                  break; 
        default:
                  break;
      }
  }
}

void menu(){
  Serial.println("");
  Serial.println("         [8]:UP");
  Serial.println("[4]:LEFT [5]:CENTER [6]:RIGHT");
  Serial.println("         [2]:DOWN");
  Serial.println("[0];MENU            [,]:PLAY/PAUSE");
  Serial.println("[+]:PAIR ON [-]:PAIR OFF [H]:HELP");
  Serial.println("");  
}

void PostProcess(){
  delay(500);                  
  Serial.println(".....ok");
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print(">");
}
