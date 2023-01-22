# Video #258: ESP32 Web Enabled - with OTA
How you can interface with your ESP32 to get information or carry out actions. Plus uploading code Over The Air in one easy step.

thumbnail goes here
### Video link: https://youtu.be/xxx  
<br>  

[![PCBWayPrototype the easy way](https://user-images.githubusercontent.com/20911308/185422574-52a4e7db-c680-4dd2-87be-1f1dd1db6a65.gif "PCBWay - up to 20% Discount on 4 & 6-layer PCBs")](https://pcbway.com/)  
**► Use coupon code **PCBWay8th-RSB** to get $10 off a $40 order! Coupon lasts for THREE months. Limited number of coupons available.**


## 1. Introduction
Using either the **Arduino IDE 2.0.x** [available here](https://bit.ly/Arduino2v0_IDE) or the **Visual Studio Code (PlatformIO) IDE** I'll talk you through getting a simple web page to be served up from your ESP32 (yes, the ESP8266 works too, but you will have to read the information on the libraries to make it work).

## 2a. Installing the libraries (Arduino method)
Go to [the following GitHub site](https://github.com/me-no-dev) and download the following libraries:

1. ESPAsyncWebServer
2. AsyncTCP (if you are using ESP8266 download ESPsyncTCP instead)

Go to the [following GitHub site](https://github.com/ayushsharma82/AsyncElegantOTA) and download the following library:

1. AsyncElegantOTA (same library for ESP32 & ESP8266)  

They will download as ZIP files with the suffix _-master_. Ignore all that! Just remember where you downloaded them to!   
Go to the Arduino IDE and click Sketch-> Include Library -> Add.ZIP library and click the downloaded library ZIP files.  
Done!  

## 2b. Installing the libraries (PlatformIO method)
Ensure your _platformio.ini_ file includes the ```lib_deps``` like this:  

![image](https://user-images.githubusercontent.com/20911308/213924408-f8dec861-7d99-42ab-a9a3-7adfa296eb5b.png)  

## 3. All code for both environments is in this GitHub!

Just click big green "CODE" button above and choose the ZIP file download to your PC. Then unzip and you have _everything_ you might need!  

## 4. ESP32 Tools settings (in the dropdown Tools menu in the Arduino IDE)  
Click [here for essential reading](https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/guides/tools_menu.html)  


## More info  
► List of all my videos
(Special thanks to Michael Kurt Vogel for compiling this)  
http://bit.ly/YouTubeVideoList-RalphBacon

► If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite (and other μControllers) journey

My channel, GitHub and blog are here:  
\------------------------------------------------------------------  
• https://www.youtube.com/RalphBacon  
• https://ralphbacon.blog  
• https://github.com/RalphBacon  
• https://buymeacoffee.com/ralphbacon  
\------------------------------------------------------------------

My ABOUT page with email address: https://www.youtube.com/c/RalphBacon/about


