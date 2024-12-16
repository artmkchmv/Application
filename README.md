# Application
This is a simple slot machine application developed in C++ using the **SFML 2.6.2** library. The project uses **CMake** for building and is intended to work with **Visual Studio 2022** on Windows.

## Requirements
- **CMake** version 3.10 or higher (download from [CMake Downloads](https://cmake.org/download/))
- **Microsoft Visual Studio 2022 (17.0)** (download from [Microsoft Downloads](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170))
- **SFML 2.6.2** (download from [SFML Downloads](https://www.sfml-dev.org/download.php))

## Steps to Build the Project

### 1. Clone the Repository

Clone the project to your local machine:
```bash
git clone https://github.com/artmkchmv/Application.git
cd Application
```

### 2. Add the SFML Library

1. Download SFML 2.6.2 (Visual C++ 17 64-bit version) from the official [SFML website](https://www.sfml-dev.org/download.php).
2. Extract the library to a convenient location.
3. Copy the entire SFML folder into the project directory.

### 3. Configure the application
1. Create the build folder in the project directory.
```bash
mkdir build
```
2. Navigate to the build folder.
```bash
cd build
```
3. Run the build configuration.
```bash
cmake -G "Visual Studio 17 2022" ..
```

### 4. Build the application
1. Open the Application.sln solution file in Visual Studio.
2. In Visual Studio, set the build configuration to x64 and Release mode. You can do this from the top toolbar, where you can select the configuration dropdown.
3. Make sure that Application is selected as the executable to be run. You can do this by right-clicking on the solution in the Solution Explorer and selecting Set as StartUp Project.
4. Click on Start or press F5 to build and run the application.
