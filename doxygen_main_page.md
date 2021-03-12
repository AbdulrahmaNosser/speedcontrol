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

- - -

@section SrcCodeDoc Source Code Documentation
##Speed control documentation
check the speed control documentation @link speed_control here@endlink.
- - -

##Switch Documentation
check the switch documentation @link switch_doc here@endlink.
- - -
@section TstDoc Testing Documentation

@details The testing is divided into 3 sections. TDD tests, State transition tests, EP + BVA tests.

##TDD
@par TDD tests are derived from the requirements of the speed control module and they are as follows:
- If “+ve” switch is pre-pressed, speed increases by 1 step if speed != maximum.
- If “-ve” switch is pre-pressed, speed decreases by 1 step if speed != minimum.
- If “p” switch is pressed for 30 seconds, speed decreases by 1 step if speed ! = minimum.
- Priority of switches is:
    + “p” switch.
    + “-ve” switch.
    + “+ve” switch.

check the documentation of the TDD tests @link TDD here@endlink.
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

check the documentation of the state transition tests @link state_transition here@endlink.
- - -

##EP + BVA
EP + BVA tests are derived from the following. As each input is independent from the other while the output is dependent on the combination of the inputs, The following schedule was made to illustrate all the possibilities.

<br>
![EP + BVA schedule](EP+BVA.png)
<br>
<br>

The previous schedule was reduced to the following schedule which has the cases that were tested.

<br>
![EP + BVA reduced schedule](EP+BVA_reduced.png)
<br>
<br>

check the documentation of EP and BVA tests @link EP_BVA here@endlink.
- - -

@note For full documentation with diagrams please refer to the files section in the index on the left.
