# Arduino
[![hackmd-github-sync-badge](https://hackmd.io/hXwUK2IzSA6LMVtYUQkTGw/badge)](https://hackmd.io/hXwUK2IzSA6LMVtYUQkTGw)

Markdown on HackMD [Link](https://hackmd.io/@jasonliu424/ntuee_micro_course)
## Morse code light sensor

### Code File

* **final project:**

[identifylist2.ino](https://github.com/jason810496/Arduino-/blob/main/identifylist2.ino)

[input_keypad_output_led_45.ino](https://github.com/jason810496/Arduino-/blob/main/input_keypad_output_led_45.ino)

[input_serial_output_led_45.ino ](https://github.com/jason810496/Arduino-/blob/main/input_serial_output_led_45.ino)

(45 means 4.5sec per unit)

**(4.5sec per unit is much more accurate than 3.0sec per unit)**

* **others**

[LightStrength.ino](https://github.com/jason810496/Arduino-/blob/main/LightStrength.ino) **(distinguish light strength and print it on keypad)**

[identifylist.ino](https://github.com/jason810496/Arduino-/blob/main/identifylist.ino)

[input_keypad_output_led_30.ino](https://github.com/jason810496/Arduino-/blob/main/input_keypad_output_led_30.ino)

[input_serial_output_led_30.ino](https://github.com/jason810496/Arduino-/blob/main/input_serial_output_led_30.ino)

(30 means 3.0sec per unit)

### 想法:
**Arduino(A)**
負責輸出摩斯電碼的LED訊號

**Arduino(B)**
負責接收LED訊號,並輸出在七段顯示器和序列埠監控視窗

**方法?**
1. (A)在發送每段訊號前,先輸出一段**特定序列**
 讓(B)知道何時開始接收

2. (B)每0.1秒判斷一次環境亮度,加入一**固定陣列**中,
 再與0-9的陣列做比較

* **Method 1**
> 開一個**固定陣列**(NowArray)**用來判斷何時接收訊號**
> 再開另一個陣列準備接收訊號(DataList)
> 每0.1sec判斷一次環境亮度(Eg:若亮度大於200判定為亮)
> 加入**NowArray**中(i.e. 將陣列元素**左移一格**再加入新的元素)
> 當**NowArray**等於我們預先設好的**特定序列**時
> **DataList**才開始接收訊號
> 最後再判別為哪個數字
> ```c++
> //for example
> int NowArray[6]={};
> int DataList[30]={}
> int CorrectArray[6]={1,1,1,1,1,1};
> /*
> intput LightStrength
> if(LightStrength>200) append 1 to NowArray;
> else append 0 in to NowArray;
> 
> check if nowarray==CorrectArray
> yes:append LightStrength to DataList
> no:continue
> */
> int num1[30]={1,0,1,0,1,1.....};
> int num2[30]={0,1,0,1,1,1.....};
> //if DataList==num1 
> //if DataList==num2.....
>
> ```
* **Method 2**
>只需開一個**固定陣列**(Array)
>每0.1sec紀錄當前狀態,並加入**Array**中
>**隨時判斷**是否有符合的數字
>```c++
>int Array[30]={};
>//intput Array now situation
>int num1[30]={1,1,1,0,1,1...};
>int num2[30]={1,1,1,0,0,0...}
>/*
>if Array==num1 output 1
>if Array==num2 output 2....
>*/ 
>```
### 總結
* **接收**

最後採取**方法2**,不過在判別數字時
還是有一定的機率會將**相鄰的數字**判別錯誤(畢竟數字0-9的Morse code 每個差異不大:**相鄰數字只有差一長或一短**)
例如:(A)發送123 而(B)接收12**4**

* **發送**

發送摩斯密碼前,需要先輸入資料

所以我們開發兩個版本

**1.** 在**序列埠監控視窗**輸入(Serial)

**2.** 在**數字板**(Keypad)

### 影片

* **succeed**

在序列埠視窗

[succeed1](https://youtu.be/j82o2HINAhA)

[succeed2](https://youtu.be/oXgZXIjwEqw)

在七段顯示器

[succeed3](https://youtu.be/KZLupLYp92o)

* **failed**

++幸運的話只差一位++

[fail1](https://www.youtube.com/watch?v=t1xPoWfHwOA)

也有可能少讀一位

[fail2](https://www.youtube.com/watch?v=XyY-_XKlXDw)

甚至差兩位

[fail3](https://www.youtube.com/watch?v=JDl9t69nRSw)

### 照片
* **Arduino(A)**
![](https://i.imgur.com/dACVFuD.jpg)


* **Arduino(B)**
![](https://i.imgur.com/RekYpIY.jpg)

### 元件:

  **Light**
  
 
 
 
 
 
 
 
 
 
 
 
![](https://i.imgur.com/GdJzMKk.jpg)

![](https://i.imgur.com/mi9K9Zx.jpg)


  **電阻**
  
  
  
  
  
  
  
  
  
![](https://i.imgur.com/2gpPDgA.jpg)


 **感光元件**(光敏電阻)
 
 
 
 
 
 
 
 
 
![](https://i.imgur.com/LIS62CI.jpg)

![](https://i.imgur.com/zUKk1Sz.jpg)


 **七段顯示器**
 
![](https://i.imgur.com/MASTk3E.jpg)

![](https://i.imgur.com/CJY0Tb5.jpg)


 **數字板**
 
![](https://i.imgur.com/UHY54ek.jpg)

 **小麵包板**
 
 ![](https://i.imgur.com/KCCcvMp.jpg)
 
 **USB**
 
![](https://i.imgur.com/opOI7wU.jpg)





