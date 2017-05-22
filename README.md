# IOPT2AC
Prototype of a toolkit to generate executable code for distributed embedded controllers, based on the code generated by IOPT Tools, a cloud-based tool for model-driven development of controllers. The toolkit includes a tool to change the generated code to allow inter-device communication though the I2C-bus specification.

![Prototype](https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/i2c_comm_prototype/distributed_controller/distributed_controller_f1.jpg)

---

### Requirements
#### OSX Tool version
* Python 2.7 (with PyObjC, os, os.path and re libs)
* OSX machine
#### All platforms version
* Python 3.6 (with os, os.path, re and tkinter libs)
#### Arduino Requirements
* 3 Arduino Boads
* 1 BreadBoard
* 8 LED
* 2 4.7k Ohm Resistors (for I2C)
* 8 220 Ohm Resistors (for LEDs)
* Hook-up wires

### IOPT-Tools

The [IOPT-Tools] framework allows the interactive creation of graphical models using IOPT nets. The user creates the Petri net graph and associates external signals and events to its transitions and places. Each event is defined based on the change of a signal value (edge up or edge down). The models can be interactively simulated [1] and its state space generated and verified to detect deadlocks, determine needed memory resources, and identify the occurrence of desirable global states [2]. The nodes can have distinct associated time domains. These models can be automatically split in the corresponding single time domain models from which code is then generated to be run in distinct processors [3], [4], [5]. In this prototype it is possible to run those nets on Arduino boards.

For more information on how to use IOPT-Tools framework please read it's [user manual].

#### Model Creation
For this paper a new account was created with the following credentials:

user: <strong>etfa2017</strong>; pass: <strong>etfa2017</strong>.

For proof of concept there were created two models, one with a single time domain (single controller needed) and another with three distinct time domains (three controllers needed).

When the user access IOPT-Tools platform with the credentials given he will found seven distinct models, corresponding to two examples. One with three controllers (```3cars*```) and another with two controllers (```simple*```). Like its stated above, in this paper we use the ```3cars``` model.

When the user has the model opened, the C language code can be generated with a click in "Generate C Code" button, as seen in the following figure.

![Generate C Code](https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/generatecode.jpg)

The above image representsthe example for a single controller model, and the code generated is available [here].
<br>
<p align="center">
   <img src="https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/single_controller.png" width="400">
</p>

For the N-time domain models an additional step needs to be completed. The user must generate the GALS Models (Globally-Asynchronous Locally-Synchronous) first with the "Decompose GALS" button. The framework will automatically generate N new models as the N is equal to the time domains present in the model.
With three time domains (proof of concept example) it will generate three models as seen in the following figure.

![GALS Models](https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/split.jpg)

In order to obtain the C code the user has to access every GALS Model and press the "Generate C Code" button.
This model code should be copied into [this folder]. You can pass this code generation step and use the previous generated models present in thr [distributed models folder]
In this IOPT-Tools account there is also a simplier example with two controllers named "simples_TD-1" and "simples_TD-2".

#### Prepare the Arduino project
Please follow this steps to prepare the Arduino project:

##### Step1
With a machine with OSX download and execute the [tool] by executing the "main.app" file present in "dist" folder or with the following command in the terminal
```sh
$ ./dist/main.app/Contents/MacOS/main
```
There is available a [tool for all platforms] that is runnable with the following command:

```sh
$ python main.py
```

##### Step2
Copy the GALS models .zip files into "zip_files" folder prensent in the IOPT2AC_tool folders

##### Step3:

Check if the models are detected automatically (see the image below). If not, please make sure that you've correctly copied the .zip files generated by the IOPT-Tools into the "zip_files" folder and then click in "Verify models in path" button.
<br>
<p align="center">
   <img src="https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/modelsfound.jpg" width="300">
   <img src="https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/modelsfound_all.jpg" width="300">
</p>

##### Step4
If the IOPT2AC_tool detects the correct number of models you are able to click in "Generate Arduino Files". As soon as the processes finishes the tool shows the models processed and their adresses.
<br><br>
<p align="center">
   <img src="https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/done.jpg" width="300">
   <img src="https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/done_all.jpg" width="300">
</p>

#### Step5
Burn the projects available in "zip_files" folder with Arduino IDE. Follow the next image to mount the correct architecture.
<br>
<p align="center">
   <img src="https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/etfa/setup.png" width="400">
</p>

The user can see the models behaviour with the Serial Monitor at 9600 bitrate.

###### Single Controller
In order to use the single controller version please use the [IOPT2AC_single.py] script.
 Run the IOPT2AC script passing the input (`-i`) file and output (`-o`) file arguments.
 The input file must be the `net_io.c` file and the output file must have `.cpp` extension in other to fully support `Wire.h` [library]. After running the script please remove the `net_io.c` file.
 ```sh
 $ rm MakeFile http_server.* dummy_gpio.c linux_sys_gpio.c raspi_mmap_gpio.c net_server.*
 $ mv net_main.c <FOLDER_NAME>.ino
 $ python IOPT2AC_single.py -i net_io.c -o net_io.cpp
 Inputs
 Digital 2 -> net1
 Digital 3 -> net2
 2
 Outputs:
 Digital 4 -> led1
 Digital 5 -> led2
 2
 Input Events:
 []
 0
 Output Events:
 []
 0
 $ rm net_io.c
 ```

For any questions with the preparation and setup please contact arturjataide@gmail.com.

Future Improvements
----
* Arduino Mega Digital Ports auto generated.

##### References
1. F. Pereira and L. Gomes, “Cloud based IOPT Petri net simulator to test and debug embedded system controllers,” in Technological Innovation for Cloud-Based Engineering Systems, ser. IFIP Advances in Informa- tion and Communication Technology, L. M. Camarinha-Matos, T. A. Baldissera, G. Di Orio, and F. Marques, Eds. Springer International Publishing, 2015, vol. 450, pp. 165–175.

2. F. Pereira, F. Moutinho, and L. Gomes, “Model-checking framework for embedded systems controllers development using iopt petri nets,” in 2012 IEEE International Symposium on Industrial Electronics, May 2012, pp. 1399–1404.

3. A. Costa and L. Gomes, “Partitioning of petri net models amenable for distributed execution,” in 2006 IEEE Conference on Emerging Technologies and Factory Automation, Sept 2006, pp. 1129–1132.

4. F. Moutinho and L. Gomes, “Asynchronous-channels within Petri net- based gals distributed embedded systems modeling,” Industrial Informat- ics, IEEE Transactions on, vol. 10, no. 4, pp. 2024–2033, Nov 2014.

5. ——, Distributed Embedded Controller Development with Petri Nets: Application to Globally-Asynchronous Locally-Synchronous Systems, 1st ed. Springer Publishing Company, Incorporated, 2015.

   [user manual]: <http://gres.uninova.pt/iopt_usermanual.pdf>
   [IOPT-Tools]: <http://gres.uninova.pt/IOPT-tools/>
   [models folder]: <https://github.com/arturataide/IOPT2AC/tree/master/models>
   [here]:<https://github.com/arturataide/IOPT2AC/blob/master/single_controller/cars3_simple.zip>
   [this folder]: <https://github.com/arturataide/IOPT2AC/tree/master/IOPT2AC_tool_all_platforms/zip_files>
   [library]: <https://www.arduino.cc/en/Reference/Wire>
   [IOPT2AC_single.py]: <https://github.com/arturataide/IOPT2AC/blob/master/old/code/single_controller/IOPT2AC_single.py>
   [Arduino IDE]: <https://www.arduino.cc/en/main/software>
   [tool]: <https://github.com/arturataide/IOPT2AC/tree/master/IOPT2AC_tool_OSX>
   [tool for all platforms]: <https://github.com/arturataide/IOPT2AC/tree/master/IOPT2AC_tool_all_platforms>
   [distributed models folder]: <https://github.com/arturataide/IOPT2AC/tree/master/distributed_models/3_cars>
