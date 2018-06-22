# Table of Contents
- [Installation Instructions](#installation-instructions)
  * [Set up the Software Environment](#set-up-the-software-environment)
  * [Start Eclipse](#start-eclipse)
  * [Create the connection with ELVIS III](#create-the-connection-with-elvis-iii)
  * [Create the Eclipse C Project](#create-the-eclipse-c-project)
  * [Install Bitfiles](#install-bitfiles)
  * [Build and Install Executable](#build-and-install-executable)
- [Examples Overview](#examples-overview)
  * [AIO](#aio)
  * [AIO N Sample](#aio-n-sample)
  * [DIO](#dio)
  * [DIO N Sample](#dio-n-sample)
  * [PWM](#pwm)
  * [Encoder](#encoder)
  * [I2C](#i2c)
  * [SPI](#spi)
  * [UART](#uart)
  * [AIIRQ](#aiirq)
  * [DIIRQ](#diirq)
  * [ButtonIRQ](#buttonirq)
  * [TimerIRQ](#timerirq)
- [Function Select Register](#function-select-register)
- [NI ELVIS III Top Board Developer's Manual](#ni-elvis-iii-top-board-developers-manual)

# Installation Instructions

  This guide helps you to configure the development environment of Eclipse ,create a connection with NI ELVIS III. You can debug or run the project on the ELVIS III with Eclipse.
  
## Set up the Software Environment

1.	To use Eclipse ,you need to first Install Java SE JDK 32-bit(x86) Java SE 6 or greater , which you can download at http://www.oracle.com/technetwork/java/javase/downloads/index.html.
2.	Install C/C++ Development Tools for NI Linux Real-Time, Eclipse Edition , which you can download at http://www.ni.com/download/labview-real-time-module-2017/6731/en/.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/picture.png)  

3.  Add the compiler path to the system environment variables
      
      a. In the Windows Control Panel, select System and Security » System » Advanced system settings to display the System Properties dialog box. <br>
      b. Click Environment Variables to display the Environment Variables dialog box.  <br>
      c. Select PATH in the User variables group box and click Edit. If PATH does not exist, click New to create one.  <br>
      d. Append the compiler path to Variable value. Delimit paths with semicolons.  <br>
                      C:\build\17.0\arm\sysroots\i686-nilrtsdk-mingw32\usr\bin\arm-nilrt-linux-gnueabi <br>
      e. Click OK to close the dialog boxes and save changes. <br>
     
4. 	Add the library path to the system environment variables
      
      a. Click New in the User variable group box to display the New User Variable dialog box. <br>
      b. In the Variable name, enter LIB_PATH. <br>
      c. In the Variable value box, enter: C:\build\17.0\arm\sysroots\cortexa9-vfpv3-nilrt-linux-gnueabi <br>
      d. Click OK to close the dialog boxes and save changes. <br>
      
      e. Click New in the User variable group box to display the New User Variable dialog box. <br>
      f. In the Variable name, enter C_INCLUDE_PATH. <br>
      g. In the Variable value box, enter: %LIB_PATH%/usr/include <br>
      h. Click OK to close the dialog boxes and save changes. <br>



>NOTE : The  paths are customized for the 2017 version of Eclipse. If you use other versions of Eclipse, update the value to use the cross-compilers directory of Eclipse.

## Start Eclipse

1.	Run Eclipse from the location where it is installed.
2.	The Select a Workspace dialog shows. Click OK.
3.	If the Welcome screen shows, click the Arrow to go to the Eclipse Workbench (C/C++ Editor)

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic2.png)  

## Create the connection with ELVIS III
1.	Click Window > Open Perspective > Other.... Select Remote System Explorer. Click OK.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic3.png)  

2.	In the Remote Systems pane's toolbar, click the Define a new connection to a remote system. The New Connection dialog shows.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic4.png)  

3.	On the Select Remote System Type step, select Linux. Click Next.
4.	On the Remote Linux System Configure step, input the Host name: the wireless IP address. Click Next.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic5.png)

5.	On the Files step, select ssh.files. Click Next.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic6.png)  

6.	On the Processes step, select processes.shell.linux. Click Next.
7.	On the Shells step, select ssh.shells. Click Next.
8.	On the SSH Terminals step, click Finish. The remote system shoes in the Remote Systems pane.
9.	In the Remote Systems pane, right click the target, then click Connect. The Enter Password dialog shows.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic7.png)  

10.	Input the user ID and the password of the ELVIS III. Click OK.
11.	The Info dialog shows. Click OK .You have successfully connected to the ELVIS III.

## Create the Eclipse C Project
       Use C examples to try how to run a project on ELVIS III with Eclipse.
1.	Click Window > Open Perspective > Other.... Select C/C++ (default). Click OK.
2.	Click File > Import... The Import dialog shows.
3.	Select General  > Existing Projects into Workspace. Click Next >
Note  Before import , you need to download the C support archive file .You can download C support archive file from……
4.	Select Select archive file. Click Browse... and select the latest build C support archive file.
5.	Check C Support file and the example to import. Click Finish.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic8.png)  

## Install Bitfiles
   Bitfiles contain information about the interfaces and registers of the hardware .Before using ELVIS III ,you need to install bitfiles in ELVIS III. You can download bitfiles from …
1.	Click Window > Open Perspective > Other.... Select Remote System Explorer. Click OK.
2.	In the Remote Systems pane's toolbar, expand Sftp Files > root. Right-click Root, and click New > Folder.The New Folder dialog shows.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic9.png)  

3.	Input the folder name /var/local/natinst/bitfiles. Click OK.
Ignore any error if the folder already exists.
4.	In the Remote Systems pane, right-click the newly created folder, click Export From Project.... The Export dialog shows.
5.	Expand the project, and export the file like NiFpga_ELVISIIIv10FPGA.lvbitx (depending on the hardware you are using). Then click Finish.

![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic10.png)  

## Build and Install Executable
1.	Click Window > Open Perspective > Other.... Select C/C++ (default). Click OK.

2.	In the Project Explorer pane, select the project. Click Project > Build Project. Wait until the project finishes building. 

>NOTE: if you select Release on the toolbar to  build the project ,you need to configure settings and tool chain of the project .

>![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic13.png)  

>   a.	In the Project Explorer pane, Right-Click the Project  > Properties .
>In the left pane ,expand C/C++ Builder > Settings . In the right pane ,click Configuration and select Release . 
>Bneath Configuration , select Tool Settings .Expand Cross GCC Compiler and configure Symbols , Includes  according to configuration in Debug .Expand Cross GCC Linker and configure libraries according to configuration in Debug .

>![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic14.png)

>   b.	In the left pane ,expand Select C/C++ Builder > Tool Chain Editor .In the right pane ,click Current builder and select CDT Internal Builder .

3.  In the Project Explorer pane, Right-Click the Project  > Properties .In the left pane ,expand Resource > Linked Resources . In the right pane ,click Linked Resources .Select the location of C support file ,click Edit….Add the path where the source file of C support file locate .Usually the path is 
        C:\Users\<administrator name>\workspace\C Support for ELVISIII\source
4.	In the Project Explorer pane, select the project. Click Run > Run Configurations .Right-click C/C++ Remote Application ,Click New .Run Configurations pane of the project shows .




![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic11.png) 

5.	Click Connection and select the target IP address to connect with the ELVIS III.
6.	In right hand pane beneath Remote Absolute File Path for C/C++ Application, click Browse to create a new folder for this project in ELVIS III .Select Remote C/C++ Application File dialog shows.
7.	Right-click My Home .Click New .Click Folder . Input New folder name .Click Finish . 
8.	Select newly created folder .Click OK .Add the project name to the Remote Absolute File Path .Add /<project name> to /home/admin/<new folder name>.Click Apply .
  
  ![](https://github.com/ni-kismet/ELVISIII_C_Examples/blob/master/docs/resources/pic12.png) 
  
9.	Click Run

# Examples Overview
NI provides the following examples for using the NI ELVIS III. Refer to the *main.c* file in each example for more information.

## AIO
  Demonstrates using the analog input and output (AIO). This example writes an initial value to AO0 on bank A and reads this value from AI0 on bank A.This example also reads the difference of the initial values on AI1 and AI5 on bank B. This example prints the values to the console.
## AIO N Sample
  Demonstrates using th analog input and output of N Sample (AIO - N Sample). This example reads a group of values from AI0 on bank A and writes a group of initial values to AO0 on bank B.This example prints the group of read values to the console.
## DIO
  Demonstrates using the digital input and output (DIO). This example writes an initial value to DIO1 on bank A and reads this value from DIO0 on bank A.This example also reads an initial value from DIO0 on bank B.This example prints the values to the console.
## DIO N Sample
  Demonstrates using th digital input and output of N Sample (AIO - N Sample). This example reads a group of values from DIO0 on bank A and writes a group of initial values to DIO0 on bank B.This example prints the group of read values to the console.
## PWM
  Demonstrates using pulse-width modulation (PWM). This example generates a PWM signal from PWM 0 on bank A.
## Encoder
  Demonstrates using the encoder. This example reads a step and direction signal from the encoder on bank A and prints the values to the console.
## I2C
  Demonstrates using the I²C. This example reads the temperature from a connected TMP102 digital temperature sensor and writes the response to the console.
## SPI
  Demonstrates using the serial peripheral interface bus (SPI). This example writes a message to the SPI bus and then prints any returned bytes to the console.
## UART
  Demonstrates using the universal asynchronous receiver/transmitter (UART). This example writes a character to the UART bus and then prints any returned character to the console.
## AIIRQ
  Demonstrates using the analog input interrupt request (IRQ). This example registers an IRQ on analog input AI0 on bank A and creates a new thread that waits for the interrupt to occur.
## DIIRQ
  Demonstrates using the digital input interrupt request. This example registers an IRQ on digital input DIO0 on connector A and creates a new thread that waits for the interrupt to occur.
## ButtonIRQ
  Demonstrates using the button interrupt request. This example registers an IRQ on the user button of the NI ELVIS III and creates a new thread that waits for the interrupt to occur.
## TimerIRQ
  Demonstrates using the timer interrupt request. This example registers an IRQ on software timer and creates a new thread that waits for the interrupt to occur.

# Function Select Register

Some examples need extra devices to connect to NI ELVIS III.Here are the input and output interfaces of these examples:

- DIO:      DIO [0:19] on bank A and bank B
- PWM:      DIO [0:19] on bank A and bank B
- Encoder:  DIO [0:1], DIO [2:3], …, DIO [18:19] on bank A and bank B
- SPI:      DIO [5:7] on bank A and bank B
- I2C:      DIO [14:15] on bank A and bank B
- UART:     DIO [16:17]  on bank A and bank B

|**NI ELVIS III**| DIO example | PWM example | Encoder example | SPI example | I2C example              |UART example| 
|:--------------:|:-----------:|:-----------:|:---------------:|:-----------:|:------------------------:|:----------:| 
| **DIO 0**      | DIO 0       | PWM 0       | ENC.A 0         |             |                          |            | 
| **DIO 1**      | DIO 1       | PWM 1       | ENC.B 0         |             |                          |            | 
| **DIO 2**      | DIO 2       | PWM 2       | ENC.A 1         |             |                          |            | 
| **DIO 3**      | DIO 3       | PWM 3       | ENC.B 1         |             |                          |            | 
| **DIO 4**      | DIO 4       | PWM 4       | ENC.A 2         |             |                          |            | 
| **DIO 5**      | DIO 5       | PWM 5       | ENC.B 2         | SPI.CLK     |                          |            | 
| **DIO 6**      | DIO 6       | PWM 6       | ENC.A 3         | SPI.MISO    |                          |            | 
| **DIO 7**      | DIO 7       | PWM 7       | ENC.B 3         | SPI.MOSI    |                          |            | 
| **DIO 8**      | DIO 8       | PWM 8       | ENC.A 4         |             |                          |            | 
| **DIO 9**      | DIO 9       | PWM 9       | ENC.B 4         |             |                          |            | 
| **DIO 10**     | DIO 10      | PWM 10      | ENC.A 5         |             |                          |            | 
| **DIO 11**     | DIO 11      | PWM 11      | ENC.B 5         |             |                          |            | 
| **DIO 12**     | DIO 12      | PWM 12      | ENC.A 6         |             |                          |            | 
| **DIO 13**     | DIO 13      | PWM 13      | ENC.B 6         |             |                          |            | 
| **DIO 14**     | DIO 14      | PWM 14      | ENC.A 7         |             | I2C.SCL                  |            | 
| **DIO 15**     | DIO 15      | PWM 15      | ENC.B 7         |             | I2C.SDA                  |            | 
| **DIO 16**     | DIO 16      | PWM 16      | ENC.A 8         |             |                          | UART.RX    | 
| **DIO 17**     | DIO 17      | PWM 17      | ENC.B 8         |             |                          | UART.TX    | 
| **DIO 18**     | DIO 18      | PWM 18      | ENC.A 9         |             |                          |            | 
| **DIO 19**     | DIO 19      | PWM 19      | ENC.B 9         |             |                          |            | 

# NI ELVIS III Top Board Developer's Manual

This manual helps users of the National Instruments ELVIS III develop a custom application top board. The manual includes information on licensing, mechanical design, electrical design, basic software interfacing, and courseware support. For information on the use of ELVIS III or administering and provisioning ELVIS III in a laboratory setting refer to the product documentation.

You can find NI ELVIS III Top Board Developer's Manual [here](./docs/NI%20ELVIS%20III%20MDK.docx).

