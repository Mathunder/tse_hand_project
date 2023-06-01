<div align="center">
    <img src="./ressources/imgs/hand_pixel_art.png" alt="Logo" width="170" height="200">
    <h3 align="center">Hand Game</h3>
    <p align="center">Hand tracking with a camera</p>
    <br />
</div>
<br>

<div>
    <a href="https://mootse.telecom-st-etienne.fr/pluginfile.php/65484/mod_resource/content/0/Enonc%C3%A9%20projet%20BDM.pdf">Wording of the project</a>
</div>
<br/>

## Structure

## 3D drawing

The idea of the drawing is to identify the elements that will always be displayed. For example, the fingers will not always be drawn, but the base of the hand will be, so there is no need for it to be coded more than once.  
A finger is to be drawn if the function that is assigned to this specific finger is given the argument `true` and vice versa.  
This applies to the `Wall` and `Hand` class.  

## Multithreading

In order to have a fluid application, we chose to use `QtConcurrent` which allows to execute a task in an independant thread. The 3D scene and the hand detection are both executed in a thread, while the rest of the application is executed normally. Thus the application runs without any major drop in performances.

## Signals

All the `signals` are emitted by the `Scene` class, which draws the 3D scene. Such behavior allows to handle every event that may arise (game over, wall passed successfully, etc). All these signals are received by the `Mainwindow` class which modifies the displayed content.

## Hand Detection

The supported hand position are the following :  
[conf1](./ressources/imgs/conf1.png)
[conf2](./ressources/imgs/conf2.png)
[conf3](./ressources/imgs/conf3.png)
[conf4](./ressources/imgs/conf4.png)
[conf5](./ressources/imgs/conf5.png)
[conf6](./ressources/imgs/conf6.png)
[conf7](./ressources/imgs/conf7.png)
[conf8](./ressources/imgs/conf8.png)
