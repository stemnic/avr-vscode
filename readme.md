# How to create AVR projects in VS Code

This instructable shows a way to configure a VS Code workspace for correct IntelliSense AVR header file inclusion and task to compile and clean the project.

To easily download tailored makefiles and accompanying resources, Atmel START is used to initialize the project. The user can choose whether to download an "empty" project and strip away the START drivers, or to download an example or self-configured project and continue work from there.

Both AVR-GCC and IAR is supported

## Prerequisites
This environment is made for MacOS. 

* VS Code
  * C/C++ Extension (ms-vscode.cpptools)
* Make installed and added to PATH
  * Either installed with Atmel Studio 7
    * Default path: `C:\Program Files (x86)\Atmel\Studio\7.0\shellutils`
  * Or use Make for Windows, can be found at <http://gnuwin32.sourceforge.net/packages/make.htm>
* For AVR-GCC compile: AVR 8-bit GNU toolchain added to PATH
  * Either installed with Atmel Studio 7
    * Default path: `C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin`
  * Or use standalone version, can be found at <https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers>
* For IAR compile: IAR Embedded Workbench for AVR

## Usage

1. Go to http://start.atmel.com and start a project
    * Create New Project -> select device -> Create New Project
    * or Browse Example -> select example -> Open Selected sample
2. Optional: Configure project, components and pinmux
3. Export Project -> check the "Makefile (standalone)" checbox -> Download Pack
4. Unzip the *.atzip to `[your project folder]`
    * Optional: Delete everything except for the `gcc`, `iar` and `include/avr` folders
5. Copy the `.vscode` folder from this repo to `[your project folder]`
6. Configure IntelliSense paths and defines
    * F1 -> C/C++: Edit Configurations (UI)
    * Update Include path to match your folder paths
    * Update Defines to match your AVR of choice:

        ```c
        /* Name of device with '__' before and after */
        __ATtiny817__ 
        /* Always same as above, but with 'AVR_' prefix */
        __AVR_ATtiny817__
        /* Used by the catch-all macro in <avr/io.h>:
         * 'tn' for tiny, i.e. tn88 for ATtiny88
         * 'm' for mega, i.e. m328P for ATmega328P 
         * 'x' for xmega, i.e. x32e5 for ATxmega32E5
         */
        __AVR_DEV_LIB_NAME__=tn817
        ```

      * Leave the other defines untouched, unless you know what you are doing
    * If you later see two identical device header files, it should be ok to delete the `[your project folder]/include/avr` folder
7. Select the C/C++ configuration you wish to use
    * F1 -> C/C++: Select a Configuration...
8. Congratulations! Now you are ready to write some code!
9. Configure the default build task
    * F1 -> Tasks: Configure Default Build Task
10. Compile
    * CTRL+Shift+B to run the default build task
    * or F1 -> Tasks: Run Task

## Programming hex files using Curiosity Nano

If you are using a Curiosity Nano development board, you can now program the device with the compiled hex file in `[your project folder]/gcc` by drag and drop to the `CURIOSITY` virtual drive.

## Debugging

Not supported that I know of, use Atmel Studio 7 or MPLABX..
