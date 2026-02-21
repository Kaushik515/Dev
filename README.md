# C++ - OOPS - Problem Solving

## How to Compile and Run C++ Files

### Compile (Create executable)
```bash
g++ filename.cpp -o filename
```

### Run the executable

**PowerShell:**
```powershell
./filename
```

**Command Prompt:**
```cmd
filename.exe
```

### If Process Is Locked
If you get "Permission denied" error, the program is still running:
```powershell
Stop-Process -Name "filename" -Force
```

## Header Includes
When including the `bits/stdc++.h` header, please use double quotes `""` instead of angle brackets `<>` to ensure the compiler finds the local file.

**Correct:**
```cpp
#include "bits/stdc++.h"
```

**Incorrect (unless configured globally):**
```cpp
#include <bits/stdc++.h>
```

## Project Structure
```
OOPS/
Sheets/
    ├── bits/
    │   └── stdc++.h
    ├── CombinedOops.cpp
    ├── Constructors.cpp
    ├── Max-Area-of-Island.cpp
    ├── No-of-Islands.cpp
    ├── Open-the-Lock.cpp
    └── Surrounded-Regions.cpp
```
