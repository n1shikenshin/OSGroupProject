# C-SCAN Disk Schedulling Simulator
TDB2043 - Operating System

## Overview
This project simulates the C-SCAN (Circular SCAN) disk schedulling algorithm using C++.

1. **C-SCAN Algorithm**
   * Moves the disk arm in one direction (UP or DOWN), servicing requests along the way.
   * Once it reaches the last track, it jumps to the opposite end and continues servicing.
   * Reduces seek time and avoids starvation.

2. **Program Features**
   * Handles UP and DOWN directions.
   * Calculates total tracks travelled.
   * Displays a formatted table of Start, Finished and Track Travelled.
   * Shows the complete service order.

---

## Objectives

* Compare how C-SCAN schedules disk I/O request efficiently.
* Calculate total distance travelled by the disk arm.
* Compare servicing order based on direction input.

---

## Project Structure

```
OSGroupProject/
├── src/
│   └── main.cpp
│   └── output.o
└── README.md
```

---

## How to Run

### Compile

Using 'g++':

```
g++ main.cpp -o output.o
```

### Run

```
./output.o
```

### Example Input

```
Enter initial arm position (0-199): 50
Enter direction (UP/DOWN) : UP
Enter number of track requests: 10
Enter track requests: 85 10 37 175 112 24 73 52 183 149
```

### Output

```
Sorted requests: 10 24 37 52 73 85 112 149 175 183

Initial Arm position: 50    Direction: UP

Start     Finished       Track Travelled
-------------------------------------------
50        52             2
52        73             21
73        85             12
85        112            27
112       149            37
149       175            26
175       183            8
183       199            16
199       0              199
0         10             10
10        24             14
24        37             13

Total Track Travelled: 395
Service Order: 52 73 85 112 149 175 183 0 10 24 37
```

---

## 👥 Team Members

* Muhammad Azrul Aiman Bin Mohamad Azlan
* Syahmi Alif Bin Shaiful Azhar
* Wan Aiman Al Mujaheed Bin Wan Hisyamuddin
* Muhammad Adam Danish Bin Nurulfuad
* Wan Harith Rifqi Bin Wan Mazli

---

## 📎 Report & Submission

* Final report included in `ULearn`
* Source code provided in `/src`
* Demonstration during presentation

---

## 📜 License

This project is developed for academic purposes under Universiti Teknologi Petronas (UTP).


---