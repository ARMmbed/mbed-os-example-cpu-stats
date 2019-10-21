![](./resources/official_armmbed_example_badge.png)
# CPU Statistics Mbed OS Example

The example project is part of the [Arm Mbed OS Official Examples](https://os.mbed.com/code/) and is the [getting started example for Mbed OS](https://os.mbed.com/docs/mbed-os/development/quick-start/index.html). It contains an application that repeatedly blinks an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

You can build the project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).
(Note: To see a rendered example you can import into the Arm Online Compiler, please see our [import quick start](https://os.mbed.com/docs/mbed-os/latest/quick-start/online-with-the-online-compiler.html#importing-the-code).)

1. [Install Mbed CLI](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).

1. Clone this repository on your system, and change the current directory to where the project was cloned:

    ```bash
    $ git clone git@github.com:armmbed/mbed-os-example-cpu-stats && cd mbed-os-example-cpu-stats
    ```

    Alternatively, you can download the example project with Arm Mbed CLI using the `import` subcommand:

    ```bash
    $ mbed import mbed-os-example-cpu-stats && cd mbed-os-example-cpu-stats
    ```


## Application functionality

The `main()` function creates an event queue and adds a function to periodically print the time spent while up, in idle mode, in sleep mode, and in deep sleep mode. It also starts a thread that blinks an LED at varying intervals in order to keep the CPU busy.

## Building and Running

1. Connect a USB cable between the USB port on the target and the host computer.
2. Run the following command to build the example project, program the microcontroller flash memory, and open a serial terminal:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash --sterm
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-cpu-stats.bin` 

Alternatively, you can manually copy the binary to the board, which you mount on the host computer over USB.

Depending on the target, you can build the example project with the `GCC_ARM`, `ARM` or `IAR` toolchain. After installing Arm Mbed CLI, run the command below to determine which toolchain supports your target:

```bash
$ mbed compile -S
```

## Expected output
The LED blinks and the serial terminal shows an output similar to the following:
```
--- Terminal on /dev/ttyACM0 - 9600,8,N,1 ---
Uptime              Idle Time           Sleep time          DeepSleep time      
1000061             913531              0                   913531              
2000061             1828212             0                   1828212             
3000061             2742923             0                   2742923             
4000061             3657635             0                   3657635             
5000061             4572315             0                   4572315             
6000061             5486998             0                   5486998             
7000061             6401676             0                   6401676             
8000061             7316387             0                   7316387             
9000061             8231098             0                   8231098             
10000061            9145803             0                   9145803 
```

### License and contributions
The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide
