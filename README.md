
# QT - FFmpeg Screen Recorder

![Qt](https://github.com/SadkDemr/QT-FFmpegScreenRecorder/blob/main/FFmpegScreenRecord/image/Screenshot%202022-08-16%20152538.png?raw=true)

An application that takes a screen recording of a computer in a simple Qt application using the FFmpeg library.

Use ffmpeg The command line allows screen recording , The command line is as follows ：


```c++
ffmpeg -f gdigrab -i desktop -framerate 60 -offset_x 0 -offset_y 0 -video_size 1600x900 -pix_fmt yuv420p -vcodec libx264 -crf 18 -threads 2 C:/Users/msdemir/Desktop/out1.mp4
```

Command Introduction ：

gdigrab: Show that we are through gdi Screen capture mode ;

framerate 30： Indicates that the frame rate of my recording is 30;

offset_x ： Upper left offset X;

offset_y ： Upper left offset Y;

video_size： The width and height to be recorded , This is I am the whole screen ;

desktop： tell ffmpeg We recorded the screen , Not a window

crf： This parameter controls transcoding , The value range of this parameter is 0–51, among 0 Lossless mode , The greater the numerical , The worse the picture quality , The smaller the generated file . Subjectively ,18~28 It's a reasonable range .18 Considered visually lossless （ From a technical point of view, of course, it is damaging ）, Its output video quality is equivalent to that of the input video .




## Installation

Install my-project with npm

```bash
//MinGw
 https://wiki.qt.io/How_to_setup_Qt_and_openCV_on_Windows

 //MSVC2017
 https://wiki.qt.io/How_to_setup_Qt_and_openCV_on_Windows_with_MSVC2017
```
    
## 🛠 Skills
Qt, Qml, C++ ... 


## Feedback

If you have any feedback, please reach out to us at msadikdemir54321@gmail.com


## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/muhammed-sadık-demir-4138821b7/)

