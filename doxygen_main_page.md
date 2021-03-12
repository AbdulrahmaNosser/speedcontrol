@mainpage speedcontrol documentation
@tableofcontents
@author Abdulrahman Hamed Nosser
@version 0.1
@date 2021-03-12
@details Testing was done using **Unity** and **Cmock**. Documentation was done using **Doxygen** and **Graphviz**. You can refer to the **[Github repo](https://github.com/AbdulrahmaNosser/speedcontrol)** to get a sense of the sequence of development.

@brief This is a documentation of the work done by Abdulrahman Nosser for solving the Vacuum Cleaner Speed Control challenge by SWIFT ACT

@section SrcCodeDoc Source code documentation
##Speed control documentation
check the speed control documentation @link speed_control here@endlink.
- - -

##Switch documentation
check the switch documentation @link switch_doc here@endlink.
- - -
@section TstDoc Testing documentation

##Overview
@details The testing is divided into 3 sections. TDD tests, State transition tests, EP + BVA tests.

@par TDD tests are derived from the requirements of the speed control module and they are as follows:
- If “+ve” switch is pre-pressed, speed increases by 1 step if speed != maximum.
- If “-ve” switch is pre-pressed, speed decreases by 1 step if speed != minimum.
- If “p” switch is pressed for 30 seconds, speed decreases by 1 step if speed ! = minimum.
- Priority of switches is:
    + “p” switch.
    + “-ve” switch.
    + “+ve” switch.

<br>
check the documentation of the TDD tests @link TDD here@endlink.
- - -

@par State transition tests could be visualized by the following diagrams. The first diagram shows the state machine of the vacuum cleaner.
![State machine diagram](StateMachine_alpha.png)

The second diagram shows the N-1 switch coverage from which each end node represents a test case.
![N-1 switch coverage diagram](N-1_coverage_alpha.png)

<br>
check the documentation of the state transition tests @link state_transition here@endlink.
- - -

@par EP + BVA tests are derived from the following. As each input is independent from the other while the output is dependent on the combination of the inputs, The following schedule was made to illustrate all the possibilities.
![EP + BVA schedule](EP+BVA.png)

The previous schedule was reduced to the following schedule which has the cases that were tested.
![EP + BVA reduced schedule](EP+BVA_reduced.png)

<br>
check the documentation of EP and BVA tests @link EP_BVA here@endlink.
- - -

##For full documentation with diagrams please refer to the files section in the index on the left.
