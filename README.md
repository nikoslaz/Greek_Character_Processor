# Greek Character Processor

## Overview
A C program that processes Greek characters with diacritics (tonos, dialitika) and converts them to their ASCII equivalents. Implements a finite state machine to handle special character sequences.

## Features

### Character Processing
- Handles both uppercase and lowercase Greek letters
- Processes diacritical marks (tonos `´` and dialitika `¨`)
- Special handling for sequences involving μ, ν (m, n) and their uppercase variants

### State Machine
| State        | Description                          |
|--------------|--------------------------------------|
| State_dflt   | Default processing state             |
| State_m      | Handling lowercase mu (μ) sequences  |
| State_M      | Handling uppercase mu (Μ) sequences  |
| State_n      | Handling lowercase nu (ν) sequences  |
| State_N      | Handling uppercase nu (Ν) sequences  |

## Implementation Details

### Character Mapping
```c
// Example mapping for lowercase alpha with tonos
charmap[0xDC][0] = 0x61;  // 'a'
charmap[0xDC][1] = TONOS;  // '´'

// Example mapping for uppercase iota with dialitika and tonos
charmap[0xC0][0] = 0x69;    // 'I'
charmap[0xC0][1] = DIALITIKA // '¨'
charmap[0xC0][2] = TONOS;   // '´'
```

## Special Sequences

| Greek Sequence | Latin Equivalent |
|----------------|------------------|
| μπ             | **b**            |
| Μπ             | **B**            |
| ντ             | **d**            |
| Ντ             | **D**            |

## Build and Run

```bash
gcc main.c -o greek_processor
./greek_processor < input.txt > output.txt
```

## Input/Output Examples

| Input    | Output         |
|----------|----------------|
| Μπαίρω   | Bairo          |
| ντύνω    | dino           |
| άέήίόύώ  | a´e´h´i´o´y´w´ |

