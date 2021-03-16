@mainpage speedcontrol documentation
@tableofcontents
@author Abdulrahman Hamed Nosser
@version 0.1
@date 2021-03-12

@brief This is a documentation of the work done by Abdulrahman Nosser for solving the Vacuum Cleaner Speed Control challenge by SWIFT ACT

@details Testing was done using **Unity** and **Cmock**. Documentation was done using **Doxygen** and **Graphviz**. You can refer to the **[Github repo](https://github.com/AbdulrahmaNosser/speedcontrol)** to get a sense of the sequence of development. Try running **run_test_cases.exe** in the project folder to run the test cases discussed bellow. Also, try running **speedcontrol_from file.exe** to get the input from **switch.txt** and output in **motor.txt**.
@see main.c for more details if you want to run from Codeblocks.

- - -

@section TimeTrigger Time Triggering

In a real life situation one must take into consideration multiple factors affecting the timing of the tasks. Starting with the switches one must take into consideration the physical bouncing of it. The sampling rate of the switch must be greater than or equal the bouncing time. Also, one must take into consideration the fastest human possible click.
<br>
The [electrical engineering journal website](https://www.eejournal.com/article/ultimate-guide-to-switch-debounce-part-4/#:~:text=As%20Jack%20Ganssle%20reported%20in,microseconds%20(or%206.2%20ms).) mentions that the maximum bounce duration is around  6.2 ms. But 20 ms is widely used as an assurance that the switch has debounced.
<br>
It is mentioned in [science daily](https://www.sciencedaily.com/releases/2018/03/180320100852.htm) that 100 ms is the fastest that a human can click a button.
<br>
From these two pieces of information **20 ms** is taken as the duration at which we calculate the switch sampling rate. Assuming that the module would need 3 samples to understand the state of the switch hence we need **60 ms** to get the state of the switch.
<br>
The motor speed control function rate in this case should be equal or less. Meaning that it will be called every **60 ms or more**. Because when calling the speed control function every 10 ms for example would result in wasted resources as it depends on the switch function to operate the motor. Furthermore, we run into the risk of having the speed control function giving wrong output if the implementation of the switch function stores the state of the switches in a manner that would induce an error in case of a repeated call without state change. 
<br>
From the durations decided we can calculate the counters of the scheduler if we opted to use one, depending on the frequency of the microcontroller.

- - -

@section SrcCodeDoc Source Code Documentation
##Speed control documentation
check the speed control documentation @link speed_control here@endlink.
- - -

##Switch Documentation
For the switch module to read from the text file correctly one must write the **switch.txt** file correctly. The first column contains the order of the switches. For example if the multiple switches were triggered at the same time they will have the same number of order. The second column contains the switch name. The Third column contains the switch state. And the last column contains the duration of the pressure. You must fill all columns separated by a single space.
<br>
<br>
![switch file structure](switch.txt file.jpg)
<br>
<br>
The speed control module outputs the motor angles in **motor.txt**.
<br>
check the switch documentation @link switch_doc here@endlink.
- - -
@section TstDoc Testing Documentation

@details The testing is divided into 3 sections. **TDD** tests, **State transition** tests, and **EP + BVA** tests. With total of 39 test cases.

##TDD
TDD tests are derived from the requirements of the speed control module and they are as follows:
- If “+ve” switch is pre-pressed, speed increases by 1 step if speed != maximum.
- If “-ve” switch is pre-pressed, speed decreases by 1 step if speed != minimum.
- If “p” switch is pressed for 30 seconds, speed decreases by 1 step if speed ! = minimum.
- Priority of switches is:
    + “p” switch.
    + “-ve” switch.
    + “+ve” switch.

check the documentation of the TDD test cases code @link TDD here@endlink.
- - -

##State Transition
State transition tests could be visualized by the following diagrams. The first diagram shows the state machine of the vacuum cleaner.

<br>
![State machine diagram](StateMachine_alpha.png)
<br>

<br>

The second diagram shows the N-1 switch coverage from which each end node represents a test case.

<br>
![N-1 switch coverage diagram](N-1_coverage_alpha.png)
<br>
<br>

check the documentation of the state transition test cases code @link state_transition here@endlink.
- - -

##EP + BVA
EP + BVA tests are derived from the following. As each input is independent from the other while the output is dependent on the combination of the inputs, The following schedule was made to illustrate all the possibilities.

| Reduced EP+BVA        ||||||
|---------------|-------------------|-------------|----------|------------|-----------|
| switch        | switch state      | motor state | duration | action     | partition |
| X             | NEGATIVE          | X           | X        | status_quo | 1         |
| NEGATIVE      | SW_S_PRE_PRESSED  | ^           | X        | ^          | ^         |
| SW_PRESSURE   | SW_S_RELEASED     | MIN         | 30       | ^          | 2         |
| ^             |  ^                | MID         | 30       | ^          | ^         |
| ^             |  ^                | MAX         | 30       | ^          | ^         |
| ^             | SW_S_PRE_PRESSED  | MIN         | 30       | ^          | ^         |
| ^             |  ^                | MID         | 30       | ^          | ^         |
| ^             |  ^                | MAX         | 30       | ^          | ^         |
| ^             | SW_S_PRESSED      | MID         | 29       | speed--    | 3         |
| ^             | ^                 | MID         | 30       | ^          | ^         |
| ^             | ^                 | MID         | 31       | ^          | ^         |
| ^             | ^                 | MIN         | 30       | status_quo | 4         |
| ^             | ^                 | MID         | 30       | speed--    | 5         |
| ^             | ^                 | MAX         | 30       | ^          | ^         |
| ^             | SW_S_PRE_RELEASED | MIN         | 30       | status_quo | 6         |
| ^             | ^                 | MID         | 30       | ^          | ^         |
| ^             | ^                 | MAX         | 30       | ^          | ^         |
| SW_MINUS      | SW_S_RELEASED     | MIN         | X        | ^          | ^         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| ^             | SW_S_PRE_PRESSED  | MIN         | X        | ^          | ^         |
| ^             | ^                 | MID         | X        | speed--    | 7         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| ^             | SW_S_PRESSED      | MIN         | X        | status_quo | 8         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| ^             | SW_S_PRE_RELEASED | MIN         | X        | ^          | ^         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| SW_PLUS       | SW_S_RELEASED     | MIN         | X        | ^          | ^         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| ^             | SW_S_PRE_PRESSED  | MIN         | X        | speed++    | 9         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | status_quo | 10        |
| ^             | SW_S_PRESSED      | MIN         | X        | ^          | ^         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| ^             | SW_S_PRE_RELEASED | MIN         | X        | ^          | ^         |
| ^             | ^                 | MID         | X        | ^          | ^         |
| ^             | ^                 | MAX         | X        | ^          | ^         |
| HIGHER_VALUES | X                 | X           | X        | ^          | ^         |
| X             | HIGHER_VALUES     | X           | X        | ^          | ^         |

<br>

The previous schedule was reduced to the following schedule which has the cases that were tested.

| Reduced EP+BVA        ||||||
|---------------|-------------------|-----------------|--------------|----------------|---------------|
| **switch**    | **switch state**  | **motor state** | **duration** | **action**     | **partition** |
| X             | NEGATIVE          | MID             | 30           | status_quo     | 1             |
| NEGATIVE      | SW_S_PRE_PRESSED  |  ^              | 30           | ^              | ^             |
| SW_PRESSURE   | SW_S_RELEASED     | MID             | 30           | status_quo     | 2             |
| ^             | SW_S_PRE_PRESSED  | MID             | 30           | ^              | ^             |
| ^             | SW_S_PRESSED      | MID             | 29           | speed--        | 3             |
| ^             | ^                 | MID             | 30           | ^              | ^             |
| ^             | ^                 | MID             | 31           | ^              | ^             |
| ^             | ^                 | MIN             | 30           | status_quo     | 4             |
| ^             | ^                 | MID             | 30           | speed--        | 5             |
| ^             | ^                 | MAX             | 30           | ^              | ^             |
| ^             | SW_S_PRE_RELEASED | MID             | 30           | status_quo     | 6             |
| SW_MINUS      | SW_S_RELEASED     | MID             | x            | status_quo     | ^             |
| ^             | SW_S_PRE_PRESSED  | MIN             | x            | ^              | ^             |
| ^             | ^                 | MID             | x            | speed--        | 7             |
| ^             | ^                 | MAX             | x            | ^              | ^             |
| ^             | SW_S_PRESSED      | MID             | x            | status_quo     | 8             |
| ^             | SW_S_PRE_RELEASED | MID             | x            | ^              | ^             |
| SW_PLUS       | SW_S_RELEASED     | MID             | x            | ^              | ^             |
| ^             | SW_S_PRE_PRESSED  | MIN             | x            | speed++        | 9             |
| ^             | ^                 | MID             | x            | ^              | ^             |
| ^             | ^                 | MAX             | x            | status_quo     | 10            |
| ^             | SW_S_PRESSED      | MID             | x            | ^              | ^             |
| ^             | SW_S_PRE_RELEASED | MID             | x            | ^              | ^             |
| HIGHER_VALUES | X                 | MID             | x            | status_quo     | ^             |
| X             | HIGHER_VALUES     | MID             | x            | ^              | ^             |
<br>

check the documentation of EP and BVA test cases code @link EP_BVA here@endlink.
- - -

@note For full documentation with diagrams please refer to the files section in the index on the left.
